import os
import platform
import sys

cson = {
    'Windows': 'C://Users//Vernon//.atom//snippets.cson',
    'Linux': '/home/atpms/.atom/snippets.cson'
}

def valid(f):
    return os.path.isfile(f) and f.endswith('.cpp') and not f.startswith('[') and not f.startswith('_')

def get_name(cpp_file):
    try:
        return cpp_file[cpp_file.index('-')+2:-4]
    except ValueError:
        return cpp_file[:-4]

snippets = [{
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
            if name == 'Template' or not line.startswith(('#include', 'using namespace', 'using ll')) or line.startswith(('#include <ext', 'using namespace __gnu')):
                print(line, end='', file=file)
        print('"""', file=file)
    else:
        print("\t\t'disabled': true", file=file)

with open(cson[platform.system()], encoding='utf-8', mode='w') as f:
    print("'.source.cpp':", file=f)
    for cpp_file in [f for f in os.listdir('.') if valid(f)]:
        with open(cpp_file, encoding='utf-8', mode='r') as source:
            make_snippet(get_name(cpp_file), get_name(cpp_file), source, f)
    for snippet in snippets:
        make_snippet(snippet['name'], snippet['prefix'], snippet['body'].splitlines(True)[1:], f)
