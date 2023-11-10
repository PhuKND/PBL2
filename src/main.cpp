#include <iostream>
#include <fstream>
#include <vector>
#include "Product.h"  // Import các lớp và thư viện cần thiết
#include "Customer.h"
#include "Order.h"
#include "Employee.h"
#include "Store.h"
#include "Payment.h"
#include "Report.h"
#include "Menu.h"

int main() {
    // Tạo danh sách sản phẩm và khách hàng
    Vector<Product> productList;
    Vector<Customer> customerList;

    // Đọc dữ liệu từ file
    LoadDataFromFile(productList, customerList);

    // Tạo đối tượng cửa hàng
    Store myStore("Siêu thị ABC", "123 Đường ABC, Thành phố XYZ");

    // Tạo đối tượng menu để tương tác với người dùng
    Menu myMenu;

    int choice;

    do {
        // Hiển thị menu và lựa chọn của người dùng
        choice = myMenu.DisplayMenu();

        switch (choice) {
            case 1:  // Thêm sản phẩm
                // Thêm sản phẩm vào danh sách sản phẩm
                Product newProduct;
                newProduct.InputProductInfo(); // Hãy cài đặt phương thức này trong lớp Product để nhập thông tin sản phẩm
                productList.push_back(newProduct);
                break;

            case 2:  // Hiển thị danh sách sản phẩm
                myStore.DisplayProductList(productList); // Hãy cài đặt phương thức này trong lớp Store để hiển thị danh sách sản phẩm
                break;

            case 3:  // Thêm khách hàng
                // Thêm khách hàng vào danh sách khách hàng
                Customer newCustomer;
                newCustomer.InputCustomerInfo(); // Hãy cài đặt phương thức này trong lớp Customer để nhập thông tin khách hàng
                customerList.push_back(newCustomer);
                break;

            case 4:  // Hiển thị danh sách khách hàng
                myStore.DisplayCustomerList(customerList); // Hãy cài đặt phương thức này trong lớp Store để hiển thị danh sách khách hàng
                break;

            case 5:  // Tạo đơn hàng
                // Hãy cài đặt logic để tạo và quản lý đơn hàng
                break;

            case 6:  // Thanh toán đơn hàng
                // Hãy cài đặt logic để thanh toán đơn hàng
                break;

            case 7:  // Tạo báo cáo
                // Hãy cài đặt logic để tạo và quản lý báo cáo
                break;

            case 8:  // Lưu dữ liệu vào file trước khi thoát
                SaveDataToFile(productList, customerList);
                std::cout << "Dữ liệu đã được lưu." << std::endl;
                break;

            case 9:  // Thoát khỏi ứng dụng
                std::cout << "Tạm biệt! Hẹn gặp lại." << std::endl;
                break;

            default:
                std::cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." << std::endl;
        }
    } while (choice != 9);

    return 0;
}

// Hàm để đọc dữ liệu từ file
void LoadDataFromFile(Vector<Product>& productList, Vector<Customer>& customerList) {
    std::ifstream inputFile("data.txt");
    if (inputFile.is_open()) {
        // Đọc dữ liệu sản phẩm từ file và thêm vào danh sách sản phẩm
        // Đọc dữ liệu khách hàng từ file và thêm vào danh sách khách hàng
        inputFile.close();
    }
}

// Hàm để lưu dữ liệu vào file
void SaveDataToFile(const Vector<Product>& productList, const Vector<Customer>& customerList) {
    std::ofstream outputFile("data.txt");
    if (outputFile.is_open()) {
        // Ghi dữ liệu sản phẩm vào file
        // Ghi dữ liệu khách hàng vào file
        outputFile.close();
    }
}
