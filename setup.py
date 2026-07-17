from setuptools import setup, Extension

setup(
    name="gap3-clib-probe",
    version="0.1.0",
    description="Gap 3 test probe: C extension with explicit libraries=['pq']",
    license="MIT",
    ext_modules=[
        Extension(
            "gap3_clib_probe._speed",
            sources=["gap3_clib_probe/speed.c"],
            libraries=["pq"],
        ),
    ],
    packages=["gap3_clib_probe"],
)
