import pathlib
import subprocess


DATA = pathlib.Path('data')


def jsonparser_output(json_file):
    out = subprocess.check_output(['./jp.out', json_file])
    return out.decode().strip()
