//2021.08.12
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Person{
public:
    int age;
    string name;
    int createDate;
};

bool compare(Person a, Person b){
    if(a.age > b.age) return false;
    else if(a.age == b.age) {
        if(a.createDate > b.createDate) return false;
        else return true;
    }
    else return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<Person> person(n);
    for(int i = 0; i < n; i++){
        cin >> person[i].age >> person[i].name;
        person[i].createDate = i;
    }

    sort(person.begin(), person.end(), compare);

    for(const Person &item: person){
        cout << item.age << ' ' << item.name << '\n';
    }
}