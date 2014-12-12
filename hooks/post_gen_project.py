# These values get populated from the template
# We use them to get the cookiecutter context
PROJECT_NAME = "{{ cookiecutter.project_name }}"
ENABLE_CPU_CODE = {{ cookiecutter.enable_cpu_code }}
ENABLE_ENGINE_CODE = {{ cookiecutter.enable_engine_code }}


import shutil

if not ENABLE_CPU_CODE:
    shutil.rmtree('../' + PROJECT_NAME + '/CPUCode')

if not ENABLE_ENGINE_CODE:
    shutil.rmtree('../' + PROJECT_NAME + '/EngineCode')
