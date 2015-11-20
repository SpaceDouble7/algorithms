//
// Created by Admin on 2015/11/20.
//

#include "dynamic_programming.h"

//************************************
// Method:    longestIncreasingSubsequence
// FullName:  zy_d_p::longestIncreasingSubsequence
// Access:    public
// Returns:   std::vector<int>
// Qualifier:
// Parameter: std::vector<int> sequence
// Description:
//	�������������е����������еĳ��ȵĺ�����
//	��Ҫ˼·��
//		ʹ�ö�̬�滮����������Ϊ:��j�ڵ�Ϊ��β�����������еĳ��ȡ�
//	 ���е��ƹ�ʽ��
//		L[j] = 1 + max(L[i]:i<j)
//	 �Ӷ��õ��˶�̬�滮�����������⹫ʽ��
//************************************
std::vector<int> zy_d_p::longestIncreasingSubsequence(std::vector<int> sequence) {
    std::vector<int> L(sequence.size());
    std::vector<int> pre(sequence.size());
    for (int idx = 0; idx < sequence.size(); ++idx) {
        int max_value = 0;
        int pos = -1;
        // �������ʹ���ڽӱ�����Ҫȫ������
        for (int _idx = 0; _idx < idx; ++_idx) {
            if (sequence[_idx] >= sequence[idx]) {
                continue;
            }
            if (L[_idx] > max_value) {
                max_value = L[_idx];
                pos = _idx;
            }
        }
        L[idx] = 1 + max_value;
        pre[idx] = pos;
    }

    int max_value = -1;
    int max_pos = -1;
    for (int idx = 0; idx < L.size(); ++idx) {
        if (L[idx] > max_value) {
            max_value = L[idx];
            max_pos = idx;
        }
    }
    std::vector<int> longest_path;
    while(max_pos != -1) {
        longest_path.push_back(max_pos);
        max_pos = pre[max_pos];
    }
    std::reverse(longest_path.begin(), longest_path.end());
    return longest_path;
}

void zy_d_p::test_longestIncreasingSubsequence()
{
    int b[] = {1,2,3,4,2,2,43,1,6,7,8,3,10};
    std::vector<int> a(b, b + sizeof(b) / sizeof(int));
    for (int idx = 0; idx < a.size(); ++idx) {
        std::cout << a[idx] << " ";
    }
    std::cout << std::endl;
    std::vector<int> longest_path = zy_d_p::longestIncreasingSubsequence(a);
    for (std::vector<int>::iterator it = longest_path.begin(); it != longest_path.end(); ++ it) {
        std::cout << a[*it] << " ";
    }
    std::cout << std::endl;
}

//************************************
// Method:    editDistance
// FullName:  zy_d_p::editDistance
// Access:    public
// Returns:   int
// Qualifier:
// Parameter: std::string s1
// Parameter: std::string s2
// Description:
//	����������ʣ��ַ������ı༭���롣
//	�����ҵ������⣺
//		���������ַ���s1,s2,���ȷֱ���i��j��
//		ԭ���⣺��distance(s1[0:i], s2[0:j])
//		�����⣺���distance(s1[0:ii], s2[0:jj])
//		���ƹ�ʽ��
//		d[i][j] = min(1 + d[i-1][j], 1+d[i][j-1], diff(i,j)+d[i-1][j-1])
//		�������壺
//		d[i][j]��ʾs1[0:i],s2[0:j]֮��ľ��롣
//		����ֵ�ֱ��ʾ��s2[j]��Ӧ��,s1[i]��Ӧ��,s1[i],s2[j]��Ӧ��
//************************************
int zy_d_p::editDistance(std::string s1, std::string s2)
{
    // �����ž���ı�
    std::vector<std::vector<int>> table;
    for (int idx = 0; idx <= s1.size(); ++ idx) {
        std::vector<int> t(s2.size() + 1);
        table.push_back(t);
    }

    // ��ʼ��һ���ַ���Ϊ�յĲ���
    for (int idx = 0; idx < table.size(); ++ idx) {
        table[idx][0] = idx;
    }
    for (int idx = 0; idx < table[0].size(); ++ idx) {
        table[0][idx] = idx;
    }

    // d[i][j] = min(1 + d[i-1][j], 1+d[i][j-1], diff(i,j)+d[i-1][j-1])
    // ���ݵ��ƹ�ʽ��������ֵ�ļ���
    int diff = 0;
    for (int i = 1; i < table.size(); ++i) {
        for (int j = 1; j < table[0].size(); ++j) {
            table[i][j] = std::min(1 + table[i-1][j], 1 + table[i][j - 1]);
            if (s1.at(i - 1) == s2.at(j - 1)) {
                diff = 0;
            } else {
                diff = 1;
            }
            table[i][j] = std::min(table[i][j], diff + table[i-1][j-1]);
        }
    }
    return table[table.size()-1][table[0].size()-1];
}

void zy_d_p::test_editDistance()
{
    std::string s1 = "exponential";
    std::string s2 = "polynomial";
    std::cout << s1 << " " << s2 << std::endl;
    std::cout << editDistance(s1, s2) << std::endl;
}
