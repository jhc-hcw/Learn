//
// Created by jhc on 2022/5/13.
//

#ifndef TEMPLE_TEMPLATE_H
#define TEMPLE_TEMPLATE_H

#endif //TEMPLE_TEMPLATE_H
using namespace std;
#include<vector>
#include<map>
#include<hash_map>
#include<unordered_map>
template<typename T>
using AddPointer =T*;

template<typename T,int Size>
struct SuperPointer:SuperPointer<AddPointer<T>,Size -1>{};
template<typename T>
struct SuperPointer<T,0>{using type=T;};

bool testt(int a,int b){
    return a & b;
}
#define showm(c,d) \
if(testt(c,d)) \
{std::cout<<"ewosl"<<std::endl;}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a,b;
        vector<int> res;
        multimap<int ,int> m;
        int count;
        multimap<int,int>::iterator it;
        for(int i=0;i<nums.size();i++){
            m.insert(map<int ,int >::value_type(nums[i],i));
        }
        for(int i=0;i<m.size();i++){
            count=m.count(target-nums[i]);
            it=m.find(target-nums[i]);
            if(count==1 && it->second!=i){
                a=i;
                b=it->second;
                break;
            }else if(count>=2){
                m.erase(it);
                i--;
            }
        }
        return {a,b};
//        for(auto i=nums.begin();i<nums.begin();i++){
//            for(auto j=nums.begin();j<nums.end();j++){
//                if(*i+*j==target){
//                    res.push_back(i-nums.begin());
//                    res.push_back(j-nums.end());
//                    map<int ,int> nl;
//                    return res;
//                }
//            }
//        }
//        return res;
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a,b;
        //multimap<int ,int> m;
       unordered_multimap<int,int> m;
        int count;
        auto it=m.begin();
        unordered_multimap<int,int>::iterator itt;
        for(int i=0;i<nums.size();i++){
            m.insert(map<int ,int >::value_type(nums[i],i));
        }
        for(;it!=m.end();it++){
            itt=m.find(target-it->first);
            if(itt!=m.end()){
                if(itt!=it){
                    a=it->second;
                    b=itt->second;
                    break;
                }
            }
        }
        return {a,b};
    }
};

#include<stack>
  //Definition for singly-linked list.
  struct ListNode {
      int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution_two {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode  *res,*temp=0,*t1=l1,*t2=l2;
        int si=0;
        while( t1 || t2 || si!=0){
            if(t1){
                si+=t1->val;
                t1=t1->next;
            }
            if(t2){
                si+=t2->val;
                t2=t2->next;
            }
            if(temp){
                temp=new ListNode(si%10);
            }else{
                res=new ListNode(si%10);
                temp=res;
            }
            si=si/10;
            if(si==0 && !t1) temp->next=t2;
            else if(si==0 && !t2) temp->next=t1;
        }
        return res;
    }
};
#include<set>
class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        unordered_map<int, int> hash;                  //<s[i], 个数>
        for (int i = 0, j = 0; j < s.size(); j++) {
            hash[s[j]]++;
            while (hash[s[j]] > 1) hash[s[i++]]--;     //出现重复的字符，前指针右移到满足条件
            result = max(result, j - i + 1);           //记录结果
        }
        return result;
    }
};
class Solution4 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        vector<int>::iterator n1 = nums1.begin(), n2 = nums2.begin();
        while (n1 != nums1.end() && n2 != nums2.end()) {
            if (*n1 < *n2) {
                res.push_back(*n1);
                n1++;
            } else {
                res.push_back(*n2);
                n2++;
            }
        }
        while (n1 != nums1.end()) {
            res.push_back(*n1);
            n1++;
        }
        while (n2 != nums2.end()) {
            res.push_back(*n2);
            n2++;
        }
        if (res.size() % 2 == 1) {
            return res[res.size() / 2];
        } else {
            double r = 0;
            r = (double(res[res.size() / 2 - 1]) + double(res[res.size() / 2])) / 2;
            return r;
        }
    }
    };

class Solution5 {
public:
    string longestPalindrome(string s) {
        int len=s.length(),t=len;
        for(int i=0;i<=len;i++){
            int j=0;
            t=len-i;
            do{
                string ss=s.substr(j,t);
                if(ishw(ss)){
                    return ss;
                }
                j++;
            }while(j<=i);
        }
        return s;
    }

    bool ishw(string s){
        if(s.length()<=1){
            return true;
        }
        if(s.length()%2==1){
            for(auto h=s.begin(),we=--s.end();h!=we;h++,we--){
                if(*h!=*we){
                    return false;
                }
            }
        }else{
            auto h=s.begin(),we=--s.end();
            for(;h+1!=we;h++,we--){
                if(*h!=*we){
                    return false;
                }
            }
            if(*h!=*we){
                return false;
            }
        }
        return true;
    }
};

class Solution6 {
public:
    string convert(string s, int numRows) {
        bool up= true;
        string res;
        string ss[numRows];
        if(s.empty()){
            return s;
        }else{
            ss[0].append(s.substr(0,1));
            s.erase(s.begin());
        }
        while(!s.empty()){
            for(int i=1;i<numRows-1 && !s.empty();i++){
                ss[i].append(s.substr(0,1));
                s.erase(s.begin());
            }
            for(int i=numRows-1;i>=0 && !s.empty();i--){
                ss[i].append(s.substr(0,1));
                s.erase(s.begin());
            }
        }
        for(int i=0;i<numRows;i++){
            res.append(ss[i]);
        }
        return res;
    }
};
#include<math.h>
class Solution7{
public:
    int reverse(int x) {
        int data=x;
        long res=0;
        while(x){
            res=res*10+x%10;
            x=x/10;
        }
        return res>INT32_MAX || res<INT32_MIN ? 0:res;
    }
};
class Solution8 {
public:
    int myAtoi(string s) {
        long res=0;
        bool b=false;
        char ff,f;
        auto it=s.begin();
        while(it!=s.end()){
            if(*it==' '){
                it++;
                if(b){
                    return 0;
                }
            }else if(*it=='0'){
                b=true;
                it++;
            }else if(*it=='+'||*it=='-'){
                f=*it;
                it++;
                if(b){
                    return 0;
                }
                break;
            }else if(*it>='0' && *it<='9'){
                break ;
            }else{break;}
        }
        while(it!=s.end() && *it>='0' && *it<='9'){
            res*=10;
            res+=*it-48;
            it++;
            if(res>=INT32_MAX){
                break;
            }
        }
        if(f=='-'){
            res=-res;
        }
        if(res>INT32_MAX){
            return INT32_MAX;
        }else if(res<INT32_MIN){
            return INT32_MIN;
        }else{
            return res;
        }
    }
};

class Solution9 {
public:
    bool isPalindrome(int x) {
        int k=x;long res=0;
       if(x<0|| (x%10==0 && x>9)){
            return false;
        }else if(x<10){
           return true;
       }
        while(k!=0){
            res*=10;
            res+=k%10;
            k=k/10;
            if(res==k || (k/10 == res  && k>9)){
                return true;
            }
        }
        return false;
    }
};

class Solution10 {
public:
    bool isMatch(string s, string p) {
        auto its=s.begin();
        auto itp=p.begin();
        char pres,prep;
        while(its!=s.end() && itp!=p.end()){
            pres=*its;
            prep=*itp;
            if(*its==*itp){
                its++;
                itp++;
            }else if(*its!=*itp){
                if(*itp=='.'){
                    //*(itp)=*its;
                    its++;
                    itp++;
                }else if (*itp=='*'){
                    if(*(itp-1)==*its || *(itp-1)=='.'){
                        its++;
                        continue;
                    }else{
                        itp++;
                    }
                }else if(*(itp+1)=='*'){
                    itp+=2;
                    continue;
                }else{
                    break;
                }
            }
        }
        if(its==s.end() && (itp==p.end() || (*itp=='*' && itp++ ==p.end()))){
            return true;
        }
        return false;
    }
};

class Solution_link_and {     //   链表的
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return 0;
        }
        ListNode *Aend = headA, *Bend = headB;
        int alen = 1, blen = 1;
        while (Aend->next) {
            Aend = Aend->next;
            ++alen;
        }
        while (Bend->next) {
            Bend = Bend->next;
            ++blen;
        }
        if (Aend == Bend) {
            ListNode *temp = alen > blen ? headA : headB;
            ListNode *temp2 = temp == headA ? headB : headA;
            int span = alen > blen ? alen - blen : blen - alen;
            for (int i = 0; i < span; ++i) {
                temp = temp->next;
            }
            while (1) {
                if (temp == temp2) {
                    return temp;
                }
                temp = temp->next;
                temp2 = temp2->next;
            }
        } else {
            return 0;
        }

    }
};

class Solution142 {
    public:
        ListNode *detectCycle(ListNode *head) {
            set<ListNode *> s;
            ListNode *temp=head;
            if(!head){
                return 0;
            }
            while(temp->next){
                if(s.find(temp)!=s.end()){
                    s.insert(temp);
                    temp=temp->next;
                }else{
                    return temp;
                }
            }
            return 0;
        }
    };
    class Solution_circlelink2 {
    public:
        ListNode *detectCycle(ListNode *head) {
           ListNode *fast=head;
           ListNode *low=head;
           while(fast){
               fast=fast->next;
               if(!fast){
                   return 0;
               }
               fast=fast->next;
               if(!fast){
                   return 0;
               }
               low=low->next;
               if(low==fast){
                   fast=head;
                   while(fast!=low){
                       fast=fast->next;
                       low=low->next;
                   }
                   return fast;
               }
           }
           return fast;
        }
    };
    class Solution_string_yiwei {
    public:
        bool isAnagram(string s, string t) {
            int a[26]={0};
            for(int i=0;i<s.size();i++){
                ++a[s[i]-'a'];
            }
            for(int i=0;i<t.size();i++){
                --a[t[i]-'a'];
            }
            for(int i=0;i<26;i++){
                if(a[i]!=0){
                    return false;
                }
            }
            return true;
        }
    };
    class Solution20 {
    public:
        bool isValid(string s) {
            stack<char> st1;
            for(auto it=s.begin();it!=s.end();it++) {
                if(*it=='{'){
                    st1.push('}');
                }else if(*it=='['){
                    st1.push(']');
                }else if(*it=='('){
                    st1.push(')');
                }else if(*it=='}' ||*it==')' ||*it==']' ){
                    if(   !st1.empty() &&st1.top()==*it){
                        st1.pop();
                    }else{
                        return false;
                    }
                }
            }
            return st1.empty();
        }
    };
    class Solution1047 {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string res;
        for(auto it=s.begin();it!=s.end();it++){
            if(!st.empty() && st.top()==*it){
                st.pop();
            }else{
                st.push(*it);
            }
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
class Solution150 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it=tokens.begin();it!=tokens.end();it++){
            if(*it=="*" ||*it=="/" ||*it=="+" ||*it=="-" ){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                if(*it=="*"){
                    st.push(x*y);
                }else if(*it == "/"){
                    st.push(y/x);
                }else if(*it =="+"){
                    st.push(x+y);
                }else if(*it=="-"){
                    st.push(y-x);
                }
            }else{
                st.push(stoi(*it));
            }
        }
        return st.top();
    }
};
#include<queue>
class Solution239 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,vector<int>::iterator >> q;
        vector<int> res;
        for(int i=0;i<k;i++){
            q.emplace(nums[i],nums.begin()+i);

        }
        //res.push_back(q.top().first);
        auto it=nums.begin();
        auto its=it+k-1;
        for(;its!=nums.end();its++,it++){
            q.emplace(*its,its);
            while(q.top().second<it){
                q.pop();
            }
            res.push_back(q.top().first);
        }
        return res;
    }
};
#include<unordered_set>
class Solution349 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> set(nums1.begin(),nums1.end());
        for(int num :nums2){
            if(set.find(num)!=set.end()){
                res.insert(num);
            }
        }
        return vector<int>(res.begin(),res.end());
    }
};
#include<math.h>
class Solution202 {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        set.insert(n);
        int res=tool(n);
        n=res;
        while(res!=1 && set.find(res)==set.end()){
            set.insert(res);
            res=tool(n);
            n=res;
        }
        if(res==1){
            return true;
        }else{
            return false;
        }
    }
    int tool(int &x){
        int res=0;
        while(x){
            res+=pow(x%10,2);
            x/=10;
        }
        return res;
    }
};

class Solution454 {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int ,int>  m1,m2;
        int sum,res=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums1.size();j++){
                sum=nums1[i]+nums2[j];
                if(!m1.emplace(sum,1).second){
                    m1[sum]++;
                }
                sum=nums3[i]+nums4[j];
                if(!m2.emplace(sum,1).second){
                    m2[sum]++;
                }
            }
        }
        for(auto it=m1.begin();it!=m1.end();it++){
            auto r=m2.find(0-(it->first));
            if(r!=m2.end()){
                res+=r->second * it->second;
            }
        }
        return res;
    }
};

class Solution383 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        for(auto i=magazine.begin();i!=magazine.end();i++){
            if(!m.emplace(*i,1).second){
                m[*i]++;
            }
        }
        for(auto i=ransomNote.begin();i!=ransomNote.end();i++){
            if(m.find(*i)!=m.end()){
                m[*i]--;
                if(m[*i]<0){
                    return false;
                }
            }else{
                return false;
            }
        }
        return true;
    }
};

class Solution15 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

    }
};

class Solution151 {
public:
    string reverseWords(string s) {
        for(auto i=s.begin();*i==' ';){
            s.erase(i);
        }
        for(auto i=s.end()-1;*i==' ';i--){
            s.erase(i);
        }
        int h=s.length()-1,r=h;
        string result;
        while(true){
            if(s[r]!=' ' && r>0){
                r--;
            }else if(s[r]==' '&& r>0){
                if(h!=r)
                    result.append(s.substr(r+1,h-r)+" ");
                r--;
                h=r;
            }else if(r==0){
                if(h==r){
                    result.append(1,s[r]);
                }else{
                    result.append(s.substr(r,h-r+1)+" ");
                }
                break;
            }
        }
        for(auto i=result.end()-1;*i==' ';i--){
            result.erase(i);
        }
        return result;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto p=head;
        int count=1;
        while(p->next){
            p=p->next;
            count++;
        }
        if(n==count){
            p=head;
            head=head->next;
            //delete(p);
            return head;
        }
        int sub=count-n;
        p=head;
        for(int i=1;i<sub;i++){
            p=p->next;
        }
        p->next=p->next->next;
        //delete(p->next);
        return head;
    }
};

class Solution28 {  //kmpo
public:
    void next_str(string s,int *next,int l){
        int k=-1,j=0;
        next[0] =-1;
        next[1] =0;
        while(j<l){
            if(k==-1 || s[k] == s[j]){
                k++;
                j++;
                next[j]=k;
            }else{
                k=next[k];
            }
        }
    }
    int strStr(string haystack, string needle) {
        int k=-1,j=-1,ll=haystack.length(),l=needle.length();
        int next[l+1];
        next_str(needle,next,l);
        while(k<l && j<ll){
            if(k==-1 || needle[k] ==haystack[j]){
                j++;k++;
            }else{
                k=next[k];
            }
        }
        if(k==l){
            return j-l;

        }else{
            return -1;
        }
    }
};
class Solution704 {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,mid;
        while(low<=high){
           mid=(low+high)/2;
           if(nums[mid]==target){
               return mid;
           }else if(nums[mid]>target){
              high=mid-1;
           }else{
               low=mid+1;
           }
        }
        return -1;
    }
};
class Solution27 {
public:
int removeElement(vector<int>& nums, int val) {
    for(auto i=nums.begin();i!=nums.end();){
        if(*i==val){
            nums.erase(i);
        }else{
            i++;
        }
    }
    return nums.size();
}
};
class Solution977 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto i=nums.begin();i!=nums.end();i++){
            *i=(*i)*(*i);
        }
        std::sort(nums.begin(),nums.end());
        return nums;
    }
};
//class Solution209 {  //overtime
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        int head=0,rear=0;
//        int w=nums.size();
//        int sum=nums[0];
//        while(true){
//           if(sum<target){
//               rear++;
//               sum+=nums[rear];
//           }
//        }
//        return 0;
//    }
//};
class Solution209 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int w=0,sum=0;
        int res=INT32_MAX;
        int head=0;
        for(int rear=0;rear<nums.size();rear++){
            sum+=nums[rear];
            while(sum>=target){
                w=rear-head+1;
                res=res<w? res : w;
                sum-=nums[head++];
            }
        }
        return res ==INT32_MAX ? 0:res;
    }
};
//矩阵绕圈圈
vector<vector<int>> generateMatrix(int n) {
    int N=n,x=0,y=0;
    int i=1;
    vector<vector<int>> res(n);
    for(int j=0;j<res.size();j++){
        res[j].resize(n);
    }
    for(;N>0;N-=2){
        for(int j=0;j<N;j++){
            res[x][y++] =i++;
        }
        y--;
        for(int j=0;j<N-1;j++){
            res[++x][y]=i++;
        }
        for(int j=0;j<N-1;j++){
            res[x][--y]=i++;
        }
        for(int j=0;j<N-2;j++){
            res[--x][y]=i++;
        }
        y++;
    }
    for(int k=0;k<n;k++){
        for(int j=0;j<n;j++){
            cout<<res[k][j]<<" ";
        }
        cout<<endl;
    }
    return  res;
    
}
class MyLinkedList {
public:
    // 定义链表节点结构体
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };

    // 初始化链表
    MyLinkedList() {
        _dummyHead = new LinkedNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
        _size = 0;
    }

    // 获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
    int get(int index) {
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        while(index--){ // 如果--index 就会陷入死循环
            cur = cur->next;
        }
        return cur->val;
    }

    // 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    // 在链表最后面添加一个节点
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则置为0，作为链表的新头节点。
    void addAtIndex(int index, int val) {
        if (index > _size || index < 0) {
            return;
        }
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    // 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return;
        }
        LinkedNode* cur = _dummyHead;
        while(index--) {
            cur = cur ->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }

    // 打印链表
    void printLinkedList() {
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
   private:
    int _size;
    LinkedNode* _dummyHead;

};
class Solution24 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *f,*s,*t;
       t=head;
       if(!head || !head->next){
        return head;
       }else{
        f=t;
        s=f->next;
        f->next=s->next;
        s->next=f;
        head=s;
        t=f;
       }
       while(t&&t->next&&t->next->next){
            f=t->next;
            s=f->next;
            f->next=s->next;
            s->next=f;
            t->next=s;
            t=f;
       }
       return head;
    }
};
class Solution739 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {  //提交超快！！！！
        const int l=temperatures.size();
        vector<int> res(l);
        int leng=l-1;
        res[leng]=0;int offset;
        leng--;
        int value;
        for(;leng>=0;leng--){
            offset=leng+1;
            value=1;
            while(true){
                if(temperatures[leng]<temperatures[offset]){
                    res[leng]=value;
                    break;
                }else{
                    if(res[offset]==0){
                        res[leng]=0;
                        break;
                    }
                    value+=res[offset];
                    offset+=res[offset];
                }
            }
        }
        return res;
    }
};