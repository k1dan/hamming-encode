#include <bits/stdc++.h>
using namespace std;

string ReadFile(string fileName) {
    string result;
    string line;
    ifstream myfile(fileName);
    if (myfile.is_open()) {
        while (getline (myfile, line)) {
            result = result + line;
        }
        myfile.close();
    }
    return result;
}   

int up_div(int first, int second) {
    return first/second + (first%second ? 1 : 0);
}

string *DivideBlocksFour(string code, string arr[], int blocksAmount) {
    int counter = 0;
    for (int i=0; i<blocksAmount; i++) {
        for (int j=0; j<4; j++) {
            arr[counter][j] = code[4*i+j];
        }
        counter++;
        cout << "b" << counter << ": " << arr[counter-1] << endl;
    }
    return arr;
}

string *DivideBlocksEleven(string code, string arr[], int blocksAmount) {
    int counter = 0;
    for (int i=0; i<blocksAmount; i++) {
        for (int j=0; j<11; j++) {
            arr[counter][j] = code[11*i+j];
        }
        counter++;
        cout << "b" << counter << ": " << arr[counter-1] << endl;
    }
    return arr;
}

string HammingEncodeEleven(string arr[], int blocksAmount) {
    string encoded;
    for (int i=0; i<blocksAmount; i++) {
        cout << "block" << i+1 << endl;
        string result = "0000000000000000";
        result[3] = arr[i][0];
        result[5] = arr[i][1];
        result[6] = arr[i][2];
        result[7] = arr[i][3];
        result[9] = arr[i][4];
        result[10] = arr[i][5];
        result[11] = arr[i][6];
        result[12] = arr[i][7];
        result[13] = arr[i][8];
        result[14] = arr[i][9];
        result[15] = arr[i][10];
        
        int res1 = 0;
        // p1
        cout << "p1: b5+b9+b13+b3+b7+b11+b15 = "; 
        cout << result[5]<<"+"<<result[9]<<"+"<<result[13]<<"+"<<result[3]<<"+"<<result[7]<<"+"<<result[11]<<"+"<<result[15]<<" = ";
        res1 = (int(result[5]) - 48) + (int(result[9]) - 48) + (int(result[13]) - 48) + (int(result[3]) - 48) +
        (int(result[7]) - 48) + (int(result[11]) - 48) + (int(result[15]) - 48);
        if (res1%2 == 0) {
            result[1] = '0';
        } else {
            result[1] = '1';
        }
        cout << result[1] << endl;
        
        // p2
        int res2 = 0;
        cout << "p2: b6+b10+b14+b3+b7+b11+b15 = "; 
        cout << result[6]<<"+"<<result[10]<<"+"<<result[14]<<"+"<<result[3]<<"+"<<result[7]<<"+"<<result[11]<<"+"<<result[15]<<" = ";
        res2 = (int(result[6]) - 48) + (int(result[10]) - 48) + (int(result[14]) - 48) + (int(result[3]) - 48) +
        (int(result[7]) - 48) + (int(result[11]) - 48) + (int(result[15]) - 48);
        if (res2%2 == 0) {
            result[2] = '0';
        } else {
            result[2] = '1';
        }
        cout << result[2] << endl;
        
        // p4
        int res3 = 0;
        cout << "p4: b5+b6+b7+b12+b13+b14+b15 = "; 
        cout << result[5]<<"+"<<result[6]<<"+"<<result[7]<<"+"<<result[12]<<"+"<<result[13]<<"+"<<result[14]<<"+"<<result[15]<<" = ";
        res3 = (int(result[5]) - 48) + (int(result[6]) - 48) + (int(result[7]) - 48) + (int(result[12]) - 48) +
        (int(result[13]) - 48) + (int(result[14]) - 48) + (int(result[15]) - 48);
        if (res3%2 == 0) {
            result[4] = '0';
        } else {
            result[4] = '1';
        }
        cout << result[4] << endl;
        
        // p8
        int res4 = 0;
        cout << "p8: b9+b10+b11+b12+b13+b14+b15 = "; 
        cout << result[9]<<"+"<<result[10]<<"+"<<result[11]<<"+"<<result[12]<<"+"<<result[13]<<"+"<<result[14]<<"+"<<result[15]<<" = ";
        res4 = (int(result[9]) - 48) + (int(result[10]) - 48) + (int(result[11]) - 48) + (int(result[12]) - 48) +
        (int(result[13]) - 48) + (int(result[14]) - 48) + (int(result[15]) - 48);
        if (res4%2 == 0) {
            result[8] = '0';
        } else {
            result[8] = '1';
        }
        cout << result[4] << endl;
        
        // p0
        int res5 = 0;
        cout << "p0: b1+b2+b3+b4+b5+b6+b7+b8+b9+b10+b11+b12+b13+b14+b15 = ";
        cout << result[1]<<"+"<<result[2]<<"+"<<result[3]<<"+"<<result[4]<<"+"<<result[5]<<"+"<<result[6]<<"+"<<result[7]<<"+"<<result[8]<<"+"<<result[9]<<"+"<<result[10]<<"+"<<result[11]<<"+"<<result[12]<<"+"<<result[13]<<"+"<<result[14]<<"+"<<result[15]<<" = ";
        res5 = res1+res2+res3+res4;
        if (res5%2 == 0) {
            result[0] = '0';
        } else {
            result[0] = '1';
        }
        cout << result[0] << endl;
        
        encoded = encoded + result;
        cout << "Encoded bitstring: " << result << endl << endl;
    }
    return encoded;
}

string HammingEncodeFour(string arr[], int blocksAmount) {
    string encoded;
    for (int i=0; i<blocksAmount; i++) {
        cout << "block" << i+1 << endl;
        string result = "00000000";
        result[3] = arr[i][0];
        result[5] = arr[i][1];
        result[6] = arr[i][2];
        result[7] = arr[i][3];
        
        int res1 = 0;
        // p1
        cout << "p1: b3+b5+b7 = "; 
        cout << result[3]<<"+"<<result[5]<<"+"<<result[7]<<" = ";
        res1 = (int(result[3]) - 48) + (int(result[5]) - 48) + (int(result[7]) - 48);
        if (res1%2 == 0) {
            result[1] = '0';
        } else {
            result[1] = '1';
        }
        cout << result[1] << endl;
        
        int res2 = 0;
        // p2
        cout << "p1: b3+b6+b7 = "; 
        cout << result[3]<<"+"<<result[6]<<"+"<<result[7]<<" = ";
        res1 = (int(result[3]) - 48) + (int(result[6]) - 48) + (int(result[7]) - 48);
        if (res2%2 == 0) {
            result[2] = '0';
        } else {
            result[2] = '1';
        }
        cout << result[2] << endl;
        
        int res3 = 0;
        // p3
        cout << "p1: b5+b6+b7 = "; 
        cout << result[5]<<"+"<<result[6]<<"+"<<result[7]<<" = ";
        res1 = (int(result[5]) - 48) + (int(result[6]) - 48) + (int(result[7]) - 48);
        if (res3%2 == 0) {
            result[3] = '0';
        } else {
            result[3] = '1';
        }
        cout << result[3] << endl;
        
        int res4 = 0;
        // p0
        cout << "p0: b1+b2+b3+b4+b5+b6+b7 = "; 
        cout << result[1]<<"+"<<result[2]<<"+"<<result[3]<<"+"<<result[4]<<"+"<<result[5]<<"+"<<result[6]<<"+"<<result[7]<<" = ";
        res1 = (int(result[1]) - 48) + (int(result[2]) - 48) + (int(result[3]) - 48) +
        (int(result[4]) - 48) + (int(result[5]) - 48) + (int(result[6]) - 48)+ (int(result[7]) - 48);
        if (res4%2 == 0) {
            result[0] = '0';
        } else {
            result[0] = '1';
        }
        cout << result[0] << endl;
        encoded = encoded + result;
        cout << "Encoded bitstring: " << result << endl << endl;
    }
    return encoded;
}

int main() {
    
    string fileName = "new.txt";
    string code;
    
    cout << "Step 1" << endl;
    code = ReadFile(fileName);
    cout << code << endl;
   
    int codeSize = code.size();
    
    // blocks by four
    int blocksAmountFour = up_div(codeSize, 4);
    string b4[blocksAmountFour];
    for (int i=0; i < blocksAmountFour; i++) {
        b4[i] = "0000";
    }
    
    // blocks by eleven
    int blocksAmountEleven = up_div(codeSize, 11);
    string b11[blocksAmountEleven];
    for (int i=0; i < blocksAmountEleven; i++) {
        b11[i] = "000000000000";
    }
    
    cout << "-----------------------" << endl;
    cout << endl;
    cout << "Step 2" << endl;
    cout << "Step 2.1" << endl;
    string *blocksEleven = DivideBlocksEleven(code, b11, blocksAmountEleven);
    cout << "-----------------------" << endl;
    cout << "Step 2.2" << endl;
    string *blocksFour = DivideBlocksFour(code, b4, blocksAmountFour);
    
    cout << "-----------------------" << endl;
    cout << endl;
    cout << "Step 3" << endl;
    cout << "Step 3.1" << endl;
    string encodedEleven = HammingEncodeEleven(blocksEleven, blocksAmountEleven);
    ofstream myfile1;
    myfile1.open("file1.txt");
    myfile1 << encodedEleven << endl;
    myfile1.close();
    cout << "-----------------------" << endl;
    cout << "Step 3.2" << endl;
    string encodedFour = HammingEncodeFour(blocksFour, blocksAmountFour);
    ofstream myfile2;
    myfile2.open("file2.txt");
    myfile2 << encodedFour << endl;
    myfile2.close();
    

    return 0;
}
