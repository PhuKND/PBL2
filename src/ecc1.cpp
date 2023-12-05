#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

struct Point
{
    int x, y;
};

int mod(int a, int b)
{
    return (a % b + b) % b;
}

Point add(Point P, Point Q, int a, int p)
{
    Point R;
    int m;

    if (P.x == -1)
        return Q;
    if (Q.x == -1)
        return P;

    if (P.x != Q.x || P.y != Q.y)
    {
        int dx = mod(Q.x - P.x, p);
        int dy = mod(Q.y - P.y, p);
        int dx_inv = -1; 
        for (int i = 1; i < p; ++i)
        {
            if ((dx * i) % p == 1)
            {
                dx_inv = i;
                break;
            }
        }
        if (dx_inv != -1)
        {
            m = (dy * dx_inv) % p;
        }
        else
        {
            return {-1, -1};
        }
    }
    else
    {
        m = (3 * P.x * P.x + a) % p;
        int dy_inv = -1;
        for (int i = 1; i < p; ++i)
        {
            if ((2 * P.y * i) % p == 1)
            {
                dy_inv = i;
                break;
            }
        }
        if (dy_inv != -1)
        {
            m = (m * dy_inv) % p;
        }
        else
        {
            cerr << "Error: Modular inverse does not exist." << endl;
            return {-1, -1};
        }
    }

    // Calculate R.x and R.y
    R.x = mod(m * m - P.x - Q.x, p);
    R.y = mod(m * (P.x - R.x) - P.y, p);

    return R;
}

Point multiply(Point P, int k, int a, int p)
{
    if(k == 0 ) return P ;
    Point R = {0, 1};

    for (int i = 0; i < k; i++)
    {
        R = add(R, P, a, p);
    }

    return R;
}

string decimalToBase3(int decimal)
{
    string base3 = "";
    while (decimal > 0)
    {
        base3 = char('0' + decimal % 3) + base3;
        decimal /= 3;
    }

    return base3;
}

string decimalToBase3(int decimal, int m)
{
    string base3 = "";
    while (decimal > 0)
    {
        base3 = char('0' + decimal % 3) + base3;
        decimal /= 3;
    }
    while (base3.size() < m)
    {
        base3 = "0" + base3;
    }
    return base3;
}

string coordinateToBase3(Point P)
{
    string base3x = decimalToBase3(P.x);
    string base3y = decimalToBase3(P.y);
    return base3x + " " + base3y;
}

vector<string> Buoc2_tt1(Point basepoint, int n)
{
    int m = decimalToBase3(n).size();
    vector<string> matrix_coso3;
    for (size_t i = 0; i <= n; i++)
    {
        string phantu = decimalToBase3(i, m);
        matrix_coso3.push_back(phantu);
    }
    return matrix_coso3;
}

char pointToChar(int index)
{
     if (index == 26)  
        return ' ';
    char a = '!';
    return a + index;
}

void shift_right(std::string &str)
{
    if (str.empty())
    {
        return;
    }

    char lastChar = str.back();

    for (int i = str.length() - 1; i > 0; i--)
    {
        str[i] = str[i - 1];
    }
    str[0] = lastChar;
}
std::string shift_right(std::string s, int m) {
    std::string result;
    std::istringstream iss(s);
    std::string group;
    while (std::getline(iss, group, ' ')) {
        if (group.size() > 1) {
            char temp = group.back();
            for (int j = group.size() - 1; j > 0; --j) {
                group[j] = group[j - 1];
            }
            group[0] = temp;
        }
        if (!result.empty()) {
            result += ' ';
        }
        result += group;
    }
    return result;
}


std::string shift_left(std::string s, int m) {
    for (int i = 0; i < s.size(); i += m) {
        int end = std::min(i + m, (int)s.size());
        if (end - i > 1) {
            char temp = s[i];
            for (int j = i; j < end - 1; ++j) {
                s[j] = s[j + 1];
            }
            s[end - 1] = temp;
        }
    }
    return s;
}

void CreateSets_allPoints(int n, Point basepoint, int a, int p)
{
    Point currentPoint = basepoint;
    for (size_t i = 1; i <= n; i++)
    {
        currentPoint = multiply(basepoint, i, a, p);
        cout << "(" << currentPoint.x << ", " << currentPoint.y << ") " << endl;
    }
    cout << endl;
}

int EncodeFunction(Point basepoint, int key, int n, int pos)
{
    // E(P) = [(Pi + K) mod (n)]P
    int c;

    int inv = -1; 
    for (int i = 1; i < n; ++i)
    {
        if ((basepoint.x * i) % n == 1)
        {
            inv = i;
            break;
        }
    }
    if (inv != -1)
    {
        c = mod((pos + key) * inv, n);
    }
    else
    {
        return -1; 
    }

    return c;
}

void Encode(string plaintext, Point basepoint, int n, int a, int p, int k,int m)
{
    const size_t size = plaintext.size();
    int arr[size];
    Point encodedPoint[size];
    cout << endl;
      std::string mahoa_truocshift = "";  // Initialize an empty string to store the encoded points before the shift

    cout << "Ma hoa: " << endl;
    for (size_t i = 0; i < size; i++)
    {
        int index = -1;
        for (size_t j = 0; j < n; j++)
        {
            if (plaintext[i] == pointToChar(j))
            {
                index = j;
                break;
            }
        }

        if (index != -1)
        {
            arr[i] = EncodeFunction(basepoint, k, n, index);
            encodedPoint[i] = multiply(basepoint, arr[i], a, p);

            if (!mahoa_truocshift.empty())
            {
                mahoa_truocshift += " ";
            }

            mahoa_truocshift += decimalToBase3(encodedPoint[i].x, decimalToBase3(n).size()) + " " + decimalToBase3(encodedPoint[i].y, decimalToBase3(n).size());

            cout << " (" << encodedPoint[i].x << "," << encodedPoint[i].y << ")";
        }
    }
    cout << endl;

    cout << "Trinh tu ma hoa : " << endl ;
     cout << shift_right(mahoa_truocshift,m)  << endl ; 
    
}
int base3ToDecimal(string base3)
{
    int decimal = 0;
    int power = 0;

    for (auto it = base3.rbegin(); it != base3.rend(); ++it)
    {
        decimal += ((*it) - '0') * pow(3, power);
        power++;
    }

    return decimal;
}

int convertToDecimal(std::string s) {
    int result = 0;
    for (int i = 0; i < s.size(); ++i) {
        result += (s[i] - '0') * pow(3, s.size() - 1 - i);
    }
    return result;
}

void convertToBase10(std::string s, int m) {
    for (int i = 0; i < s.size(); i += 2 * m) {
        std::string x = s.substr(i, m);
        std::cout << "(" << convertToDecimal(x);

        if (i + m < s.size()) {
            std::string y = s.substr(i + m, m);
            std::cout << ", " << convertToDecimal(y);
        }
        std::cout << ")" << std::endl;
    }
}
vector<Point> convertToPoints(const string &s, int m)
{
    vector<Point> points;

    for (int i = 0; i < s.size(); i += 2 * m)
    {
        string x = s.substr(i, m);
        int xDecimal = convertToDecimal(x);

        if (i + m < s.size())
        {
            string y = s.substr(i + m, m);
            int yDecimal = convertToDecimal(y);

            points.push_back({xDecimal, yDecimal});
        }
        else
        {
            points.push_back({xDecimal, -1});}
    }

    return points;
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1; 
}


int DecodeFunction(Point basepoint, int key, int n, int c)
{
    // D(C) = [(C - K) mod (n)]P

    int inv = modInverse(basepoint.x, n);

    if (inv != -1)
    {
        int decodedPos = mod((c - key) * inv, n);
        return decodedPos;
    }
    else
    {
        return -1; 
    }
}
std::string Decode(const std::string &ciphertext, Point basepoint, int k, int n, int m, int a, int p) {
    // Bước 1: Chuyển dãy mã cơ số 3 sang trái 1 bit
    std::string shiftedCiphertext = shift_left(ciphertext, m);

    // Bước 2: Chuyển mã cơ số 3 về điểm
    std::vector<Point> Points = convertToPoints(shiftedCiphertext, m);

    // Bước 3: Gọi DecodeFunction và giải mã
    Point P_base[n];
    int Index[Points.size()];

    for (size_t i = 1; i <= n; i++) {
        P_base[i] = multiply(basepoint, i, a, p);
        for (size_t j = 0; j < Points.size(); j++) {
            if (P_base[i].x == Points[j].x && P_base[i].y == Points[j].y) {
                std::cout << pointToChar(static_cast<int>(i - 1));
                Index[j] = i;
            }
        }
    }
    std::cout << std::endl;

    // Nhập key để giải mã
    std::cout << "Nhap key de giai ma: ";
    std::cin >> k;

    // Giải mã
    int newIndex[Points.size()];
    for (size_t i = 0; i < Points.size(); i++) {
        newIndex[i] = DecodeFunction(basepoint, k, n, Index[i]);
    }

    std::string decryptedSequence = "";
    for (size_t j = 0; j < Points.size(); j++) {
        for (size_t i = 1; i <= n; i++) {
            P_base[i] = multiply(basepoint, i, a, p);
            if (newIndex[j] == i) {
                std::cout << "( " << P_base[i].x << " ; " << P_base[i].y << ")";
                char decryptedChar = pointToChar(static_cast<int>(i));
                std::cout << decryptedChar << std::endl;
                decryptedSequence += decryptedChar;
            }
        }
    }

    std::cout << "Decrypted sequence: " << decryptedSequence << std::endl;

    return decryptedSequence;
}


int main()
{
    int n = 120;
    int a = -3;
    int p = 139;
    int m = decimalToBase3(n).size();
    Point basepoint = {1, 7};
    vector<char> pointToCharTable(n + 1, ' '); 
    vector<string> matrix_coso3 = Buoc2_tt1(basepoint, n);
    cout << "TAO TIEN TRINH : " << endl ; 

    // for (size_t i = 0; i <= n; i++)
    // {
    //     cout << matrix_coso3[i] << endl;
    // }

    for (size_t i = 0; i <= n; i++)
    {
        shift_right(matrix_coso3[i]);
    }

    // cout << "Bang cac diem tren duong cong E : " << endl;
    // CreateSets_allPoints(n, basepoint, a, p);
std::vector<Point> P_anhxa(n + 1);
cout << "Cac toa do cua cac diem tuong ung voi cac ky tu  " << endl;
for (size_t i = 0; i <= n; i++)
{
    P_anhxa[i] = multiply(basepoint, i, a, p);
    cout << "| (" << setw(5) << P_anhxa[i].x << ", " << setw(5) << P_anhxa[i].y << ") - " << pointToChar(static_cast<int>(i)) << " |";

    if ((i + 1) % 5 == 0)
    {
        cout << endl;
    }
}
cout << "-------------------------------------------------------" << endl;
cout << "Dang trinh tu la    : " << endl;
for (size_t i = 0; i <= n; i++)
{
    cout << "|" << setw(3) << matrix_coso3[i] << " |";

    // Xuống dòng sau mỗi 5 lần in
    if ((i + 1) % 5 == 0)
    {
        cout << endl;
    }
}

    cout << "-------------------------------------------------------"  << endl ;
    // Bước 1
    cout << "---------------------- Ma hoa ky tu --------------------" << endl ;
    cout << "Nhap gia tri cua key : ";
    int k;
    cin >> k;
    cin.ignore();

    //   Bước 2 : C = E( P) = [(Pi + K) mod (n)]P
    string plaintext;
    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, plaintext);

    int arr[plaintext.size()];
    Point encodedPoint[plaintext.size()];
     // Truoc khi ma hoa
cout << "Truoc khi ma hoa" << endl;
for (size_t j = 0; j < plaintext.size(); j++) {
    int index = -1;
    for (size_t i = 0; i <= n; i++) {
        if (plaintext[j] == pointToChar(i)) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        P_anhxa[index + 1] = multiply(basepoint, index , a, p);
        cout << "(" << P_anhxa[index + 1].x << ", " << P_anhxa[index + 1].y << ") - " << pointToChar(index) << endl;
    } else {
        cerr << "Khong tim thay ky tu trong bang anh xa. Ky tu: " << plaintext[j] << endl;
    }
}

    Encode(plaintext, basepoint, n, a, p, k,m );
    //  -------------------------------KẾT THÚC MÃ HÓA ---------------------------------------------

    // -------------------------------GIẢI MÃ -----------------------------------------------------
    // Bước 1 : Chuyển dãy mã cơ số 3 sang trái 1 bit
    string ciphertext;
    cout << "Nhap ban ma hoa" << endl;
    getline(cin, ciphertext);
    // ciphertext = shift_left(ciphertext, m);
    // cout << "Shift left" << endl;
    // cout << ciphertext << endl;
    //Bước 2 
    // Chuyển mã cơ số 3 về điểm
    ciphertext = shift_left(ciphertext,m) ; 
    convertToBase10(ciphertext,m) ; 
    // Bước 3 Dùng DecodeFunction
    // decode(basepoint,k,n,ciphertext,m) ;
     // Vi tri sau khi decode
     
    //  DecodeFunction(basepoint,k,n,c); 
    Point P_base[n];
    vector<Point> Points ;
    Points =  convertToPoints(ciphertext,m) ; 
    int Index[Points.size()]  ;
    cout << "Ky tu khi chua giai ma " << endl;
    basepoint = {1,7} ;
    for (size_t i = 1; i <= n; i++)
    {
        P_base[i] = multiply(basepoint, i, a, p);
            for (size_t j = 0; j < Points.size(); j++)
            {
                if (P_base[i].x == Points[j].x && P_base[i].y == Points[j].y)
                {
                   cout << pointToChar(static_cast<int>(i-1)); 
                   Index[j] = i ;
                }
            }
                    
    }
    cout << endl ; 
cout << "Nhap key de giai ma " ; 
cin >> k ; 
cout << "Sau khi giai ma " << endl;
int newIndex[Points.size()];
for (size_t i = 0; i < Points.size(); i++)
{
    newIndex[i] = DecodeFunction(basepoint, k, n, Index[i]);
}

std::string decryptedSequence = "";
for (size_t j = 0; j < Points.size(); j++)
{
    for (size_t i = 1; i <= n; i++)
    {
        P_base[i] = multiply(basepoint, i, a, p);
        if (newIndex[j] == i)
        {
            cout << "( " << P_base[i].x << " ; " << P_base[i].y << ")";
            char decryptedChar = pointToChar(static_cast<int>(i));
            cout << decryptedChar << endl;
            decryptedSequence += decryptedChar;
        }
    }
}
cout << "Decrypted sequence: " << decryptedSequence << endl;

}