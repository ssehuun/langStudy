from collections import deque

class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def bfs(node):
    if node is None:
        return
    queue = deque([node])
    while queue:
        current = queue.popleft()
        print(current.value)
        if current.left:
            queue.append(current.left)
        if current.right:
            queue.append(current.right)

# 사용 예시
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)

bfs(root)

"""output
12345
"""