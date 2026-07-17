/* Gap 3 test probe: minimal C extension that links against libpq.
 * Purpose is only to exercise setup.py's Extension(libraries=["pq"])
 * declaration for pre_check_deps.py's parse_extension_libraries() /
 * check_c_library_rpms(). Not meant to build into a usable module.
 */
#include <Python.h>
#include <libpq-fe.h>

static PyObject *speed_ping(PyObject *self, PyObject *args) {
    /* Touch a libpq symbol so the link step genuinely needs -lpq. */
    const char *version = PQlibVersion() ? "ok" : "unknown";
    return PyUnicode_FromString(version);
}

static PyMethodDef SpeedMethods[] = {
    {"ping", speed_ping, METH_NOARGS, "Return a constant string touching libpq."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef speedmodule = {
    PyModuleDef_HEAD_INIT, "_speed", NULL, -1, SpeedMethods
};

PyMODINIT_FUNC PyInit__speed(void) {
    return PyModule_Create(&speedmodule);
}
