class Solution {
public:
    
    double separateSquares(vector<vector<int>>& s) {
        double area = 0;
        vector<tuple<long long, int, int>>temp;

        for (auto sq : s) {
            int xi = sq[0], yi = sq[1], li = sq[2];
            long long v= (long long)(li) *(long long)li;
            area += (double)v;
            long long sy = yi;
            long long ey = yi + li;
            temp.emplace_back(sy, 1, li);
            temp.emplace_back(ey, 0, li);
        }

         double tarea = area / 2.0;
        sort(temp.begin(), temp.end());

        long long py = -1;
        double currArea = 0.0;
        long long sumLi = 0;

        for (auto it : temp) {
            long long y = get<0>(it);
            int t = get<1>(it);
            int li = get<2>(it);

            if (py != -1) {
                long long diff = y - py;
                double val = (double)(sumLi) * diff;

                if (sumLi > 0) {
                    if (currArea <= tarea && tarea <= currArea + val) {
                        double need = tarea - currArea;
                        double res = (double)(py) + need / sumLi;
                        return res;
                    }
                }

                currArea += val;
            }

            if (t == 1) {
                sumLi += li;
            } else {
                sumLi -= li;
            }

            py = y;
        }

        return 0.0;
    }
};