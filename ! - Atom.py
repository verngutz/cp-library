import os
import platform
import sys

cson = {
    'Windows': 'C://Users//Vernon//.atom//snippets.cson',
    'Linux': '/home/atpms/.atom/snippets.cson'
}

def valid_cpp(f):
    return os.path.isfile(f) and f.endswith('.cpp') and f[0] not in ('[', '_', '!')

def valid_py(f):
    return os.path.isfile(f) and f.endswith('.py') and f[0] not in ('[', '_', '!')

def get_name(file_name):
    try:
        return file_name[file_name.index('-')+2:file_name.index('.')]
    except ValueError:
        return file_name[:file_name.index('.')]

cpp_extras = [{
    'name': 'pi',
    'prefix': 'pi',
    'body': """
constexpr double pi = acos(-1);
"""
}, {
    'name': 'Benchmark',
    'prefix': 'Benchmark',
    'body': """
auto begin_t = chrono::high_resolution_clock::now();
auto end_t = chrono::high_resolution_clock::now();
chrono::duration<double> elapsed = end_t - begin_t;
cerr << "Elapsed time: " << elapsed.count() << endl;
"""
}, {
    'name': 'Memo Reset',
    'prefix': 'Memo Reset',
    'body': """
memset(mem, -1, sizeof mem);
"""
}, {
    'name': 'For Loop',
    'prefix': 'For Loop',
    'body': """
for(int ${1:i} = ${2:0}; ${1:i} <$3 ${4:n}; ${1:i}++) {
    $5
}
"""
}, {
    'name': 'For Loop (Double)',
    'prefix': 'For Loop (Double)',
    'body': """
for(int ${1:i} = ${2:0}; ${1:i} <$3 ${4:n}; ${1:i}++) {
    for(int ${5:j} = ${6:0}; ${5:j} <$7 ${8:m}; ${5:j}++) {
        $9
    }
}
"""
}, {
    'name': 'Foreach Bit',
    'prefix': 'Foreach Bit',
    'body': """
for(int ${1:i}${1:i} = ${2:mask}, ${1:i} = ctz(${1:i}${1:i}); ${1:i}${1:i} > 0; ${1:i}${1:i} &= ~(${1:i}${1:i} & -${1:i}${1:i}), ${1:i} = ctz(${1:i}${1:i})) {
    $3
}
"""
}, {
    'name': 'for each',
    'prefix': 'foreach',
    'body': ''
}, {
    'name': 'for iterator',
    'prefix': 'forit',
    'body': ''
}]

def make_snippet(name, prefix, body, file):
    print(f"\t'{name}':", file=file)
    print(f"\t\t'prefix': '{prefix}'", file=file)
    if body:
        print("\t\t'body': \"\"\"", file=file)
        for line in body:
            if (name  == 'Template'
                or not line.startswith(('#include <', 'using namespace', 'using ll', 'template <typename T> using lim', 'from', 'import'))
                or line.startswith(('#include <ext', 'using namespace __gnu'))):
                print(line, end='', file=file)
        print('"""', file=file)
    else:
        print("\t\t'disabled': true", file=file)

with open(cson[platform.system()], encoding='utf-8', mode='w') as f:
    for source_file, valid_f, extras in [('.source.cpp', valid_cpp, cpp_extras), ('.source.python', valid_py, [])]:
        print(f"'{source_file}':", file=f)
        for file_name in [f for f in os.listdir('.') if valid_f(f)]:
            with open(file_name, encoding='utf-8', mode='r') as source:
                make_snippet(get_name(file_name), get_name(file_name), source, f)
        for snippet in extras:
            make_snippet(snippet['name'], snippet['prefix'], snippet['body'].splitlines(True)[1:], f)
