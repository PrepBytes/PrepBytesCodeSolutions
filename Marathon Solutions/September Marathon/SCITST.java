import java.util.*;

 class solution {
    int[] visited;
    void explore(int u, HashMap<Integer, ArrayList<Integer>> d, ArrayList<Integer> l,int[] visited) {

        visited[u] = 1;
        l.add(u);
        for(int i: d.get(u)) {
            if(visited[i] == 0) {
                explore(i, d, l, visited);
            }
        }
    }
    ArrayList<ArrayList<Integer>> connect(HashMap<Integer, ArrayList<Integer>> d, int[]visited) {
        ArrayList<Integer> l = new ArrayList<>();
        ArrayList<ArrayList<Integer>> l1 =new ArrayList<>();
        for(int i = 0; i < d.size(); i++) {
            if(visited[i] == 0) {
                explore(i, d, l, visited);
                l1.add(l);
                l = new ArrayList<>();
            }
        }
        return (l1);
    }
    public void solve() {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        visited = new int[n];
        int m = in.nextInt();
        HashMap<Integer, ArrayList<Integer>> d = new HashMap<>();
        for(int i = 0; i < n; i++) {
            d.put(i, new ArrayList<>());
        }

        for(int i = 0; i < m; i++) {
            int u = in.nextInt();
            int v = in.nextInt();
            d.get(u).add(v);
            d.get(v).add(u);
        }
        ArrayList<ArrayList<Integer>> l=connect(d,visited);
        int s=(n*(n-1))/2;

        for (ArrayList<Integer> integers : l) {
            n = integers.size();
            s -= (n * (n - 1)) / 2;
        }
        System.out.println(s);
    }

    public static void main(String[] args) {
        (new solution()).solve();
    }
}

