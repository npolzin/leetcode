#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> lookup_map;
  for (int i = 0; i < nums.size(); i++) {
    int current = nums[i];
    int candidate = target - current;
    bool is_in_lookup_map = lookup_map.find(candidate) != lookup_map.end();
    if (is_in_lookup_map)
      return {lookup_map[candidate], i};
    lookup_map[current] = i;
  }
  return {};
}

int main(int argc, char** argv) {
  std::vector<int> nums = {2, 7, 11, 15};
  std::vector<int> result = twoSum(nums, 9);
  std::copy(result.begin(), result.end(),
    std::ostream_iterator<int>(std::cout, " "));
  return 0;
}
