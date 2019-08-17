# ����һ��ͼ���⣬�����ǽڵ㣬����������ڱ�Ȩֵ�����ǰѸ�ͼ��������ͼ������Ϊ�������򣬶�Ӧ��ȨֵΪ���������
# ��˱ߺͷ���߻�Ϊ��������������·������·���ϵı�Ȩֵ������˼��ɵõ�����������ɴ�򷵻�-1.

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        # ����ͼ��equations�ĵ�һ����Եڶ������value��Ķ�Ӧֵ���ڶ�����Ե�һ������䵹��
        graph = {}
        for (x, y), v in zip(equations, values):
            if x in graph:
                graph[x][y] = v
            else:
                graph[x] = {y: v}
            if y in graph:
                graph[y][x] = 1/v
            else:
                graph[y] = {x: 1/v}
        
        # dfs��Ѱ��s��t��·�������ؽ�����˺�ı�Ȩ�ؼ����
        def dfs(s, t) -> int:
            if s not in graph:
                return -1
            if t == s:
                return 1
            for node in graph[s].keys():
                if node == t:
                    return graph[s][node]
                elif node not in visited:
                    visited.add(node)  # ��ӵ��ѷ��ʱ����ظ�����
                    v = dfs(node, t)
                    if v != -1:
                        return graph[s][node]*v
            return -1

        # �������query��ֵ
        res = []
        for qs, qt in queries:
            visited = set()
            res.append(dfs(qs, qt))
        return res

        