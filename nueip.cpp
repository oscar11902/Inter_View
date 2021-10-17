/*
Name:Jyun-Teng Chen
Language:c++
*/
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

// 1.inherit, interface

class Vehicle{

    Vehicle();
    ~Vehicle();

    public:
        int wheel;
        int speed; 
};

class Car : Vehicle{

};

class Morto : Vehicle{

};

// ****************************************

// 2.

void test2(){
    string str = "人易科技:上 機 測 試 - 演算法"; 
    str.replace(str.find(":"),1 ,"：");
    cout << str << endl;

    int i = str.find(" ",i);
    while(i != string::npos){
        int index = str.find(" ");
        if(str[i+1] != '-' && str[i-1] != '-')str.erase(i,1);
        i = str.find(" ",i+1);
    }
    cout << str << endl;

    int index1 = str.find("：");
    int index2 = str.find("-");

    char buffer[20];
    int len = str.copy(buffer, index2 - index1 - 3, index1+3);
    buffer[len] = 0;
    cout << buffer << endl << endl;

}
// ****************************************

// 3.

void test3(){
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> arr1,arr2;
    int sum_even = 0, sum_odd = 0;
    for(int &n : arr){
        if(n & 1 == 1){
            arr1.push_back(n);
            sum_odd += n;
        }else{
            arr2.push_back(n);
            sum_even += n;
        }
    }

    cout << sum_odd - sum_even << endl;
    for(int &n : arr1)cout << n << " ";
    cout << endl;
    for(int &n : arr2)cout << n << " ";
    cout << endl;
    cout << endl;

}
// ****************************************

// 4.

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
    return;
}

void sort(int left, int right, int* arr){
    if(left > right)return;
    int i = left - 1, j = left;
    for(; j < right ; j++){
        if(arr[j] < arr[right]){
            ++i;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);
    sort(left, i, arr);
    sort(i+2, right, arr);
}

void test4(){
    int arr[12] = {77,5,5,22,13,55,97,4,796,1,0,9};
    for(int &n : arr)cout << n << ' ';
    cout << endl;
    sort(0,11,arr);
    for(int &n : arr)cout << n << ' ';
    cout << endl << endl;
}

int find(int n, vector<int> arr){
    for(int i = 0 ; i < arr.size() ; ++i){
        if(arr[i] == n)return i;
    }
    return -1;
}

void test5(){
    int arr1[12] = {77,5,5,22,13,55,97,4,796,1,0,9};
    int arr2[10] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> a1,a2,a3,a4,a5;
    a1.assign(arr1,arr1+12);
    a2.assign(arr2,arr2+10);

    for(int i = 0 ; i < a1.size() ; ++i){
        int index = find(a1[i], a2);
        if( index > -1)a3.push_back(a1[i]);
        if( index == -1)a4.push_back(a1[i]);
        a5.push_back(a1[i]);
    }
    for(int &n : a2){
        a5.push_back(n);
    }
    for(int &n : a3){
        int index = find(n, a5);
        a5.erase(a5.begin()+index);
    }

    for(int &n : a3)cout << n << ' ';
    cout << endl;
    for(int &n : a4)cout << n << ' ';
    cout << endl;
    for(int &n : a5)cout << n << ' ';
    cout << endl << endl;

}

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        for(int i = 0 ; i < nums.size() ; ++i){
            int t = target - nums[i];
            for(int j = i+1 ; j < nums.size() ; ++j){
                if(t == nums[j]){
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                }
            }
        }
        return ans;
    }

int main(){

    test2();
    test3();
    test4();
    test5();


    return 0;
}