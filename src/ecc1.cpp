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
        // Calculate m = (Q.y - P.y) / (Q.x - P.x) mod p
        int dx = mod(Q.x - P.x, p);
        int dy = mod(Q.y - P.y, p);

        int dx_inv = -1; // initialize to an invalid value

        // Find the modular inverse of dx
        for (int i = 1; i < p; ++i)
        {
            if ((dx * i) % p == 1)
            {
                dx_inv = i;
                break;
            }
        }

        // If modular inverse exists
        if (dx_inv != -1)
        {
            m = (dy * dx_inv) % p;
        }
        else
        {
            // Handle the case where modular inverse doesn't exist
            // You may want to add error handling or use a different approach
            // based on your requirements.
            cerr << "Error: Modular inverse does not exist." << endl;
            // You can return an error value or handle it in some appropriate way.
            // For now, I'm returning the point at infinity.
            return {-1, -1};
        }
    }
    else
    {
        // Calculate m = (3 * P.x^2 + a) / (2 * P.y) mod p
        m = (3 * P.x * P.x + a) % p;
        int dy_inv = -1; // initialize to an invalid value

        // Find the modular inverse of 2 * P.y
        for (int i = 1; i < p; ++i)
        {
            if ((2 * P.y * i) % p == 1)
            {
                dy_inv = i;
                break;
            }
        }

        // If modular inverse exists
        if (dy_inv != -1)
        {
            m = (m * dy_inv) % p;
        }
        else
        {
            // Handle the case where modular inverse doesn't exist
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
    Point R = {0, 1}; // Initialize R to the point at infinity

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

Point base3ToCoordinate(string base3)
{
    int decimal = 0;
    int power = 0;

    for (char digit : base3)
    {
        decimal = decimal * 3 + (digit - '0');
        power++;
    }

    Point P;
    P.y = decimal % 139;
    P.x = (decimal - P.y) / 139;

    return P;
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
// Hàm ánh xạ giữa điểm và ký tự ASCII
char pointToChar(int index)
{
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

    // Find the modular inverse of basepoint.x
    int inv = -1; // initialize to an invalid value
    for (int i = 1; i < n; ++i)
    {
        if ((basepoint.x * i) % n == 1)
        {
            inv = i;
            break;
        }
    }

    // If modular inverse exists
    if (inv != -1)
    {
        c = mod((pos + key) * inv, n);
    }
    else
    {
        // Handle the case where modular inverse doesn't exist
        cerr << "Error: Modular inverse does not exist." << endl;
        return -1; // You can return an error value or handle it in some appropriate way
    }

    return c;
}
void Encode(string plaintext, Point basepoint, int n, int a, int p, int k)
{
    const size_t size = plaintext.size();
    int arr[size];
    Point encodedPoint[size];

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
            cout << " (" << encodedPoint[i].x << "," << encodedPoint[i].y << ")";
        }
    }
    cout << endl;

    cout << "Ma hoa (base 3): " << endl;
    for (size_t i = 0; i < size; i++)
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << decimalToBase3(encodedPoint[i].x,decimalToBase3(n).size()) << " " << decimalToBase3(encodedPoint[i].y,decimalToBase3(n).size());
    }
    cout << endl;
}

int DecodeFunction(Point basepoint, int key, int n, int pos)
{
    // D(C) = [(Ci - K) mod (n)]P
    int m;

    // Find the modular inverse of basepoint.x
    int inv = -1; // initialize to an invalid value
    for (int i = 1; i < n; ++i)
    {
        if ((basepoint.x * i) % n == 1)
        {
            inv = i;
            break;
        }
    }

    // If modular inverse exists
    if (inv != -1)
    {
        m = mod((pos - key) * inv, n);
    }
    else
    {
        // Handle the case where modular inverse doesn't exist
        cerr << "Error: Modular inverse does not exist." << endl;
        return -1; // You can return an error value or handle it in some appropriate way
    }

    return m;
}


int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
    {
        if ((a * x) % m == 1)
        {
            return x;
        }
    }

    cerr << "Error: Modular inverse does not exist." << endl;
    return -1; // You can return an error value or handle it in some appropriate way
}

void Decode(string ciphertext, Point basepoint, int n, int a, int p, int k)
{
    cout << "Giai ma: ";
    for (size_t i = 0; i < ciphertext.size(); i += 2)
    {
        string base3x_str = ciphertext.substr(i, 1);
        string base3y_str = ciphertext.substr(i + 1, 1);

        int base3x = stoi(base3x_str);
        int base3y = stoi(base3y_str);

        Point encodedPoint = {base3x, base3y};
        int inv_k = modInverse(k, n);
        if (inv_k != -1)
        {
            Point decodedPoint = multiply(encodedPoint, inv_k, a, p);

            // Chuyển điểm đã giải mã thành ký tự ASCII và in ra
            int index = mod(decodedPoint.x + n * decodedPoint.y, n);
            cout << pointToChar(index);
        }
    }

    cout << endl;
}

int main()
{
    int n = 86;
    int a = 17;
    int p = 139;
    Point basepoint = {1, 7};
    vector<char> pointToCharTable(n + 1, ' '); // Khởi tạo vector với khoảng trắng

    // Bước 2,3 trong thuật toán tạo tiến trình
    vector<string> matrix_coso3 = Buoc2_tt1(basepoint, n);
    for (size_t i = 0; i <= n; i++)
    {
        cout << matrix_coso3[i] << endl;
    }

    // Bước 4 chuyển dịch sang phải
    for (size_t i = 0; i <= n; i++)
    {
        shift_right(matrix_coso3[i]);
    }

    cout << "Sau khi dich chuyen sang phai  : " << endl;
    for (size_t i = 0; i <= n; i++)
    {
        cout << matrix_coso3[i] << endl;
    }

    // cout << "Bang cac diem tren duong cong E : " << endl;
    // CreateSets_allPoints(n, basepoint, a, p);
    Point P_anhxa[n];
    cout << "Anh' xa. " << endl;
    for (size_t i = 1; i <= n; i++)
    {
        P_anhxa[i] = multiply(basepoint, i, a, p);
        cout << "(" << P_anhxa[i].x << ", " << P_anhxa[i].y << ") - " << pointToChar(static_cast<int>(i - 1)) << endl;
    }

    // Bước 1
    cout << "Nhap gia tri cua khoa' bat ky` : ";
    int k;
    cin >> k;
    cin.ignore();

    // Bước 2 : C = E( P) = [(Pi + K) mod (n)]P
    // string plaintext;
    // cout << "Nhap chuoi can ma hoa: ";
    // getline(cin, plaintext);

    // int arr[plaintext.size()];
    // Point encodedPoint[plaintext.size()];

    // for (size_t i = 0; i < plaintext.size(); i++)
    // {
    //     int index = -1;
    //     for (size_t j = 0; j < n; j++)
    //     {
    //         if (plaintext[i] == pointToChar(j))
    //         {
    //             index = j;
    //             break;
    //         }
    //     }

    //     if (index != -1)
    //     {
    //         arr[i] = EncodeFunction(basepoint, k, n, index);
    //         encodedPoint[i] = multiply(basepoint, arr[i], a, p);
    //         cout << " (" << encodedPoint[i].x << "," << encodedPoint[i].y << ")" << endl;
    //     }
    //     cout << endl;
    // }
    // Encode(plaintext,basepoint,n,a,p,k) ;
    // -------------------------------KẾT THÚC MÃ HÓA ---------------------------------------------

    // -------------------------------GIẢI MÃ -----------------------------------------------------
    cout << "Nhap khoa giai ma : " ; 
    int k2 ;
    cin >> k2 ; 
    // Bước 2: C = E(P) = [(Pi + K) mod (n)]P
    string ciphertext;
    cout << "Nhap chuoi can giai ma: ";
    cin.ignore();
    getline(cin, ciphertext);

    Decode(ciphertext, basepoint, n, a, p, k2);
    cout << "STOP!";
    return 0;
}