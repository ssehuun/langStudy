class TreeNode:
    def __init__(self, value):
        self.value = value
        self.children = []

    def add_child(self, child_node):
        self.children.append(child_node)

    def __repr__(self, level=0):
        ret = "\t" * level + repr(self.value) + "\n"
        for child in self.children:
            ret += child.__repr__(level+1)
        return ret


class Tree:
    def __init__(self, root_value):
        self.root = TreeNode(root_value)

    def __repr__(self):
        return repr(self.root)


if __name__ == "__main__":
    tree = Tree("root")

    child_a = TreeNode("child_a")
    child_b = TreeNode("child_b")

    tree.root.add_child(child_a)
    tree.root.add_child(child_b)

    child_a1 = TreeNode("child_a1")
    child_a2 = TreeNode("child_a2")

    child_a.add_child(child_a1)
    child_a.add_child(child_a2)

    child_b1 = TreeNode("child_b1")
    child_b.add_child(child_b1)

    print(tree)

