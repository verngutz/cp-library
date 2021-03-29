from collections import namedtuple
fedge = namedtuple('fedge', ('u', 'v', 'c', 'f'))
fedge.__reversed__ = lambda self: fedge(self.v, self.u, 0, 0)
fedge.resid = lambda self: self.c - self.f
