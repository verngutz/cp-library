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
    'name': 'Read Array',
    'prefix': 'Read Array',
    'body': """
int ${4:n};
cin >> ${4:n};
#define N ${2:100'000}
static ${1:int} ${3:a}[N+1];
for(int i = 1; i <= ${4:n}; i++) {
    cin >> ${3:a}[i];
}
"""
}, {
    'name': 'Read Vector',
    'prefix': 'Read Vector',
    'body': """
int ${3:n};
cin >> ${3:n};
vector<${1:int}> ${2:a}(${3:n} + 1);
for(int i = 1; i <= ${3:n}; i++) {
    cin >> ${2:a}[i];
}
"""
}, {
    'name': 'Read Grid',
    'prefix': 'Read Grid',
    'body': """
int ${4:n}, ${5:m};
cin >> ${4:n} >> ${5:m};
#define N ${2:1000}
static ${1:int} ${3:a}[N+1][N+1];
memset(${3:a}, 0, sizeof ${3:a});
for(int i = 1; i <= ${4:n}; i++) {
    for(int j = 1; j <= ${5:m}; j++) {
        cin >> ${3:a}[i][j];
    }
}
"""
}, {
    'name': 'For Loop (0-indexed)',
    'prefix': 'For Loop (0-indexed)',
    'body': """
for(int ${2:i} = 0; ${2:i} < ${1:n}; ${2:i}++) {
    $3
}
"""
}, {
    'name': 'For Loop (1-indexed)',
    'prefix': 'For Loop (1-indexed)',
    'body': """
for(int ${2:i} = 1; ${2:i} <= ${1:n}; ${2:i}++) {
    $3
}
"""
}, {
    'name': 'For Loop (Double, 0-indexed)',
    'prefix': 'For Loop (Double, 0-indexed)',
    'body': """
for(int ${3:i} = 0; ${3:i} < ${1:n}; ${3:i}++) {
    for(int ${4:j} = 0; ${4:j} < ${2:m}; ${4:j}++) {
        $5
    }
}
"""
}, {
    'name': 'For Loop (Double, 1-indexed)',
    'prefix': 'For Loop (Double, 1-indexed)',
    'body': """
for(int ${3:i} = 1; ${3:i} <= ${1:n}; ${3:i}++) {
    for(int ${4:j} = 1; ${4:j} <= ${2:m}; ${4:j}++) {
        $5
    }
}
"""
}, {
    'name': 'For Loop',
    'prefix': 'for',
    'body': ''
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
    print("\t'{}':".format(name), file=file)
    print("\t\t'prefix': '{}'".format(prefix), file=file)
    if body:
        print("\t\t'body': \"\"\"", file=file)
        for line in body:
            if (name  == 'Template'
                or not line.startswith(('#include', 'using namespace', 'using ll', 'from', 'import'))
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
