```py
class UnionFindSet(object):
    def __init__(self, data_list):
        self.father_dict = {}
        self.size_dict = {}
        for node in data_list:
            self.father_dict[node] = node
            self.size_dict[node] = 1
    def find_head(self, node):
        father = self.father_dict[node]
        if(node != father):
            father = self.find_head(father)
        self.father_dict[node] = father
        return father
    def is_same_set(self, node_a, node_b):
        return self.find_head(node_a) == self.find_head(node_b)
    def union(self, node_a, node_b):
        if node_a is None or node_b is None:
            return
        a_head = self.find_head(node_a)
        b_head = self.find_head(node_b)
        if(a_head != b_head):
            a_set_size = self.size_dict[a_head]
            b_set_size = self.size_dict[b_head]
            if(a_set_size >= b_set_size):
                self.father_dict[b_head] = a_head
                self.size_dict[a_head] = a_set_size + b_set_size
            else:
                self.father_dict[a_head] = b_head
                self.size_dict[b_head] = a_set_size + b_set_size
```

[下载](/templates/python/并查集/并查集.py)
