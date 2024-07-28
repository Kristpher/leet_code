class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> path(n);
        for (int i = 0; i < flights.size(); i++) {
            path[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
        }

     

        vector<int> dis(n, INT_MAX);
        queue<tuple<int, int, int>>pq;
        
        dis[src] = 0;
        pq.push({0, src, 0});
        
        int minim = INT_MAX;
        
        while (!pq.empty()) {
            auto it = pq.front();
            pq.pop();

            int d = get<0>(it);
            int node = get<1>(it);
            int stops = get<2>(it);
             //cout<<d<<" "<<node<<" "<<stops<<endl; 
            if (node == dst) {
               
                if (stops-1 <= k) {
                    minim = min(minim, d);
                     //cout<<"hi";
                    cout<<minim;
                }
                continue;
            }

            if (stops > k) continue;

            for (auto& i : path[node]) {
                int next_node = i.first;
                int dist = i.second;

                if (dis[next_node] > d + dist) {
                    dis[next_node] = d + dist;
                  
                    pq.push({d+dist, next_node,stops+1});
                }
            }
        }

        return minim == INT_MAX ? -1 : minim;
    }
};
