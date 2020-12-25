#include <iostream>
#include <vector>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::cout;
using std::endl;
using std::vector;

VectorXd CalculateRMSE(const vector<VectorXd> &estimations,
    const vector<VectorXd> &ground_truth);

int main() {
  /**
   * Compute RMSE
   */
  vector<VectorXd> estimations;
  vector<VectorXd> ground_truth;

  // the input list of estimations
  VectorXd e(4);
  e << 1, 1, 0.2, 0.1;
  estimations.push_back(e);
  e << 2, 2, 0.3, 0.2;
  estimations.push_back(e);
  e << 3, 3, 0.4, 0.3;
  estimations.push_back(e);

  // the corresponding list of ground truth values
  VectorXd g(4);
  g << 1.1, 1.1, 0.3, 0.2;
  ground_truth.push_back(g);
  g << 2.1, 2.1, 0.4, 0.3;
  ground_truth.push_back(g);
  g << 3.1, 3.1, 0.5, 0.4;
  ground_truth.push_back(g);

  // call the CalculateRMSE and print out the result
  cout << CalculateRMSE(estimations, ground_truth) << endl;

  return 0;
}

VectorXd CalculateRMSE(const vector<VectorXd> &estimations,
    const vector<VectorXd> &ground_truth) {

  VectorXd rmse(4);
  rmse << 0,0,0,0;

  // TODO: YOUR CODE HERE
  // check the validity of the following inputs:
  //  * the estimation vector size should not be zero
  //  * the estimation vector size should equal ground truth vector size
  if (estimations.empty() || ground_truth.empty()) {
    std::cerr << "empty input data to CalculateRMSE() function." << std::endl;
    return rmse;
  }
  if (estimations.size() != ground_truth.size()) {
    std::cerr << "estimations and ground truth data have different sizes." << std::endl;
    return rmse;
  }

  // TODO: accumulate squared residuals
  VectorXd se_sum(4);
  se_sum << 0,0,0,0;
  for (int i=0; i < estimations.size(); ++i) {
    VectorXd se = estimations[i] - ground_truth[i];
    se = se.array() * se.array();
    se_sum += se;
  }

  // TODO: calculate the mean
  VectorXd se_mean(4);
  se_mean = se_sum / estimations.size();

  // TODO: calculate the squared root
  rmse = se_mean.array().sqrt();

  // return the result
  return rmse;
}
