#include <iostream>
#include <utility>
#include <stack>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;
// The letter class creates letter objects to store the distance and optimal action for the editdistnace function
class letter{
private:
    int distance;
    string actions;
public:
    letter(){
        distance = 0;
        actions = "";
    }
    void change_distance(int x){
        distance = x;
    }
    int get_distance() {
        return distance;
    }
    void new_action(string x){
        actions = std::move(x);
    }
    string get_action(){
        return actions;
    }
};

int EditDistance(string x, string y){
    //Checks to see if the first word is empty, if so enter every character from the second word
    if (x.length()==0){
        cout << "You need " << y.length() << " actions: Enter every character from the word \"" << y << "\"" << endl;
        return y.length();
    }
    //Checks to see if the second word is empty, if it is we delete every character in the first word
    if (y.length()==0){
        cout << "You need " << x.length() << " actions: Delete every character in the word \"" << x << "\"" << endl;
        return x.length();
    }
    cout << "The shortest edit distance from the word \"" << x << "\" to \"" << y << "\":\n" << endl;
    // Creates a 2d letter array that instantiates every column and row with the default values of "actions" and "distance" in the letter object
    letter editdistnace[x.length()+1][y.length()+1];
    // Fills all first column letter distance variable with numbers, starting at 1 in row 2, incrementing up by 1 until the last row is reached
    for (int i = 1; i < x.length()+1; i++){
        editdistnace[i][0].change_distance(i);
    }
    // Fills the first row with numbers in the letter distance variable, starting at 1 in column 2, incrementing up by one until the last column is reached
    for (int j = 1; j < y.length()+1; j++){
        editdistnace[0][j].change_distance(j);
    }
    // Perform the edit distance algorithm on strings x and y
    // This for loop traverses the rows of the 2d array, starting at row 1
    for (int i = 1; i < x.length()+1; i++){
        // This for loop traverses the columns of the 2d array, starting at column 1
        for (int j = 1; j < y.length()+1; j++){
            // If the characters are the same at the corresponding positions, we do not need to perform any action
            if (x[i-1] == y[j-1]){
                editdistnace[i][j].change_distance(editdistnace[i-1][j-1].get_distance());
                editdistnace[i][j].new_action("Keep " + string(1,x[i-1]));
            // If the letters do not match at the corresponding positions we need to take the min edit value from either A[i-1][j-1], A[i-1][j], or A[i][j-1]
            } else {
                int mindist = min({editdistnace[i-1][j-1].get_distance(), editdistnace[i-1][j].get_distance(), editdistnace[i][j-1].get_distance()});
                // if the edit distance matches A[i-1][j], we Delete the character at the i-1 in x
                if (editdistnace[i-1][j].get_distance() == mindist){
                    editdistnace[i][j].new_action("Delete " + string(1, x[i-1]));
                // If the edit distance matches A[i][j-1], we Insert the character from j-1 in y
                } else if (editdistnace[i][j-1].get_distance() == mindist){
                    editdistnace[i][j].new_action("Insert " + string(1, y[j-1]));
                // Else we substitute character x[i-1] with y[j-1]
                } else {
                    editdistnace[i][j].new_action("Replace " + string(1, x[i-1]) + " with " + string(1, y[j-1]));
                }
                // We change the distance at A[i][j] with the minimum from the previous three cases +1
                editdistnace[i][j].change_distance(mindist +1);
            }
        }
    }
    // This prints out the 2d array to show the edit distance from any point
    cout << "The 2d array of the optimal amount of edits needed at each position" << endl;
    for (int i = 0; i < x.length()+1; i++){
        for (int j = 0; j < y.length()+1; j++){
            cout << setw(3) << left << editdistnace[i][j].get_distance() << " ";
        }
        cout << endl;
    }
    cout << endl;
    // This block of code starts at the bottom most right corner on where the shortest edit distance is needed
    // we traverse the graph from there to reach A[1][1] by working backwards, using the same logic previously with adjustments
    // We push the optimal action into a stack
    stack<string> act;
    int xlen = x.length();
    int ylen = y.length();
    while(xlen >= 1 && ylen >= 1){
        act.push(editdistnace[xlen][ylen].get_action());
        int minact = min({editdistnace[xlen-1][ylen-1].get_distance(),editdistnace[xlen][ylen-1].get_distance(),editdistnace[xlen-1][ylen].get_distance()});
        if(editdistnace[xlen][ylen].get_distance() == editdistnace[xlen-1][ylen-1].get_distance() && x[xlen-1] == y[ylen-1]){
            ylen--;
            xlen--;
        }
        else if (editdistnace[xlen][ylen-1].get_distance() == minact){
            ylen--;
        }else if (editdistnace[xlen-1][ylen].get_distance() == minact){
            xlen--;
        }else {
            ylen--;
            xlen--;
        }
    }
    // This loop runs until the stack becomes empty, the loop prints the string on top of the stack then pops it out
    cout << "Steps needed to make the edit: " << endl;
    while (!act.empty()){
        cout << act.top() << endl;
        act.pop();    }
    // The final action the function performs is to return the shortest distance edit of the array
    // This shortest distance should be located at the bottom right most corner of the 2d array
    return editdistnace[x.length()][y.length()].get_distance();
}

int main(){
    int distance = EditDistance("goblin", "golden");
    cout << "The amount of edits needed are " << distance << endl;
    return 0;
}
