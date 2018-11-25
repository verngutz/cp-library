template <typename T> struct splaytree {
    splaytree *l, *r, *p;
    int size;
    T val, sum;
    splaytree(T val, splaytree* p = nullptr) : l(nullptr), r(nullptr), p(p), size(1), val(val), sum(val) {
        while(p) {
            p->size++;
            p->sum += val;
            p = p->p;
        }
    }
    void rotate() {
        if(this == p->l) {
            p->l = r;
            if(r) r->p = p;
            r = p;
            if(l) { // remove l from p subtree
                p->size -= l->size;
                p->sum -= l->sum;
            }
            if(p->r) { // add r to this subtree
                size += p->r->size;
                sum += p->r->sum;
            }
        } else {
            p->r = l;
            if(l) l->p = p;
            l = p;
            if(r) { // remove r from p subtree
                p->size -= r->size;
                p->sum -= r->sum;
            }
            if(p->l) { // add l to this subtree
                size += p->l->size;
                sum += p->l->sum;
            }
        }
        // add p to this subtree
        size++;
        sum += p->val;
        // remove this from p subtree
        p->size--;
        p->sum -= val;
        splaytree* g = p->p;
        p->p = this;
        if(g) (g->l == p ? g->l : g->r) = this;
        p = g;
    }
    splaytree* splay() {
        while(p) {
            if(not p->p) {
                rotate();
            } else if((this == p->l and p == p->p->l) or (this == p->r and p == p->p->r)) {
                p->rotate();
                rotate();
            } else {
                rotate();
                rotate();
            }
        }
        return this;
    }
    splaytree* insert(T key) {
        splaytree*& side = key < val ? l : r;
        return side ? side->insert(key) : (side = new splaytree(key, this))->splay();
    }
    splaytree* find(T key) {
        if(val == key) {
            return splay();
        } else {
            splaytree* side = key < val ? l : r;
            if(side) {
                return side->find(key);
            } else {
                return splay();
            }
        }
    }
    splaytree* max() {
        return r ? r->max() : this;
    }
    static splaytree* join(splaytree* l, splaytree* r) {
        if(l and r) {
            splaytree* new_root = l->max()->splay();
            new_root->r = r;
            new_root->size += r->size;
            new_root->sum += r->sum;
            r->p = new_root;
            return new_root;
        } else {
            return l ? l : r;
        }
    }
    splaytree* erase() {
        splay();
        if(l) l->p = nullptr;
        if(r) r->p = nullptr;
        return splaytree::join(l, r);
    }
};
template <typename T> struct splaytree_interface {
    splaytree<T>* root = nullptr;
    splaytree<T>* find(T key) {
        root = root ? root->find(key) : root;
        return root and root->val == key ? root : nullptr;
    }
    splaytree<T>* insert(T key) {
        return root = root ? root->insert(key) : new splaytree<T>(key);
    }
    splaytree<T>* erase(T key) {
        return root = find(key) ? find(key)->erase() : root;
    }
};
