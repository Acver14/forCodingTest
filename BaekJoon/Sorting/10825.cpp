//2021.08.13
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Student{
public:
    int kor;
    int eng;
    int math;
    string name;
};

bool compare(Student a, Student b){
    if(a.kor < b.kor){
        return false;
    }else if(a.kor == b.kor){
        if(a.eng > b.eng){
            return false;
        }
        else if(a.eng == b.eng){
            if(a.math < b.math) {
                return false;
            }
            else if(a.math == b.math){
                string aName = "";
                string bName = "";
                for(char ch: a.name){
                    aName += ch;
                }
                for(char ch: b.name){
                    bName += ch;
                }
                return aName < bName;
            }
            else return true;
        }else return true;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Student> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
    }

    sort(v.begin(), v.end(), compare);

    for(const Student &i: v){
        cout << i.name << '\n';
    }
}