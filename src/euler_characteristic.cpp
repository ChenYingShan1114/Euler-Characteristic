#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi = 0;
  // ADD YOUR CODE HERE

  // calculate # of edge
  Eigen::MatrixXi E = edges(F);

  // calculate # of vertex
  std::vector<int> V_tmp;
  bool exist = false;
  for (int i = 0; i < F.rows(); i++) {
    for (int j = 0; j < 3; j++) {

      // test already add or not
      for (int k = 0; k < V_tmp.size(); k++) {
        exist = false;
        if (F(i, j) == V_tmp[k]) {
          exist = true;
          break;
        }
      }
      
      if (!exist) {
        V_tmp.push_back(F(i, j));
      }

    }
  }

  Chi = V_tmp.size() - E.rows() + F.rows();
  return Chi;
}
