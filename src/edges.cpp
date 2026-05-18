#include "edges.h"

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  E.resize(0, 2);

  // ADD YOUR CODE HERE

  // calculate # of edge
  std::vector<std::pair<int, int>> E_tmp;
  int start = -1, end = -1;
  bool undirect_edge_exist = false;
  for (int i = 0; i < F.rows(); i++) {
    for (int j = 0; j < 3; j++) {
      if (j == 2) {
        start = F(i, j); end = F(i, 0);
      } else {
        start = F(i, j); end = F(i, j+1);
      }

      // find undirect edge exist or not
      for (int k = 0; k < E_tmp.size(); k++) {
        undirect_edge_exist = false;
        if (start == E_tmp[k].second && end == E_tmp[k].first) {
          E_tmp.erase(E_tmp.begin() + k); 

          // Resize to add one row while keeping existing columns
          E.conservativeResize(E.rows() + 1, Eigen::NoChange);
          // Assign values to the new last row (index starts at 0)
          E.row(E.rows() - 1) << start, end;

          undirect_edge_exist = true;
          break;
        }
      }

      if (!undirect_edge_exist) {
        E_tmp.push_back({start, end});
      }

    }
  }
  return E;
}
