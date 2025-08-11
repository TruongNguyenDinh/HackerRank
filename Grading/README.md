Topic : [Hacker Rank]([Grading Students | HackerRank](https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true))

```cpp
vector<int> gradingStudents(vector<int> grades) {
    vector<int> res; // Vector result
    for(auto x : grades){ // For each 
        if(x<38) res.push_back(x); // The first condition
        else if(x/5*5+5 - x <=2){ // check the diff between the grade and the next multiple of 5
            res.push_back(x/5*5+5);
        }
        else{ // else
            res.push_back(x);
        }
    }
    return res;
}
```


