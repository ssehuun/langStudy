class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def dfs_recursive(node):
    if node is None:
        return
    print(node.value)
    dfs_recursive(node.left)
    dfs_recursive(node.right)


def dfs_stack(node):
    if node is None:
        return
    stack = [node]
    while stack:
        current = stack.pop()
        print(current.value)
        if current.right:
            stack.append(current.right)
        if current.left:
            stack.append(current.left)


# 사용 예시
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)

dfs_recursive(root)
dfs_stack(root)

"""output
1 2 4 5 3
"""