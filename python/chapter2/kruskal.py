class Kruskal_UnionFind():
    """
    クラスカル法つきUnion Findクラス

    Attributes
    -----------
    edges : list
        辺の集合
        辺は[from, to, cost]のリスト
    rank : list
        各要素の深さ
    par : list
        各要素の根の要素
    counter : list
        各要素の子要素の数
    """

    def __init__(self, N):
        self.edges = []
        self.rank = [0] * N
        self.par = [i for i in range(N)]
        self.counter = [1] * N

    def add(self, u, v, d):
        """
        辺を追加

        Parameters
        -----------
        u : int
            from
        v : int
            to
        d : int
            cost
        """
        self.edges.append([u, v, d])

    def find(self, x):
        """
        要素xの根を見つける

        Parameters
        -----------
        x : int
            要素

        Returns
        --------
        root : int
            xの根の要素
        """
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def unite(self, x, y):
        """
        木の併合

        Parameters
        -----------
        x : int
            要素
        y : int
            要素
        """
        x = self.find(x)
        y = self.find(y)
        if x != y:
            z = self.counter[x] + self.counter[y]
            self.counter[x], self.counter[y] = z, z
        if self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def size(self, x):
        """
        要素が属する木の要素数

        Parameters
        -----------
        x : int
            要素

        Returns
        --------
        cnt : int
            xの属する木の要素数
        """
        x = self.find(x)
        return self.counter[x]

    def same(self, x, y):
        """
        同じ木に属しているか判定

        Parameters
        -----------
        x : int
            要素
        y : int
            要素

        Returns
        --------
        same : bool
            同じ木に属するか
        """
        return self.find(x) == self.find(y)

    def Kruskal(self):
        """
        クラスカル法による最小全域木のコスト

        Returns
        --------
        min_cost : int
            最小全域木のコスト
        """
        edges = sorted(self.edges, key=lambda x: x[2])
        min_cost = 0
        for e in edges:
            if not self.same(e[0], e[1]):
                self.unite(e[0], e[1])
                min_cost += e[2]
        return min_cost
