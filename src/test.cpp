#include "include/Employee.h"
#include "DataManager.cpp"
#include "Vector.cpp"
#include "Vector_Class.cpp"
#include "include/Food.h"
#include "include/ElectricalProduct.h"
#include "include/Houseware.h"
#include "include/Order.h"
#include "Menu.cpp"
#include"C:\Users\nguye\Downloads\Ky3\PBL2\src\Date.h"
#include"C:\Users\nguye\Downloads\Ky3\PBL2\src\Time.h"
#include"include/Discount.h"
int main()
{
    // Order order ;
    // Customer cus ;
    // Vector_Class<Food> data ;
    // DataManager<Food> food ;
    // food.GetData(data,"data/input_output/food.txt") ;
    // cus.BuyProduct(order,data.at(2) , 2) ;
    // order.Display(cout) ;
    // data.at(1).Display() ;
    
    Menu menu ;
    Discount dis1(1,"DUT",20,20,1) ; 
  dis1.setCouponCode("DUT") ; 
    Discount dis2(2,"ITF",19,1,1) ;
    Discount dis3(3,"HCMUS",30,1,1) ;
    Discount dis4(4,"UIT",22,1,1) ; 

    dis2.setCouponCode("ITF") ; 
    dis3.setCouponCode("HCMUS") ; 
    dis4.setCouponCode("UIT") ; 
   
    menu.discountManager.AddToLists(dis1);
    // menu.discountManager.AddToLists(dis2);
    // menu.discountManager.AddToLists(dis4);
    // menu.discountManager.AddToLists(dis3);


    menu.run();
    // DataManager<Discount> discountManager ;
    // discountManager.GetData(discountManager.lists,"data/input_output/discount.txt") ; 
    // for (size_t i = 0; i < discountManager.lists.getSize(); i++)
    // {
    //     cout << discountManager.lists.at(i) ;
    // }
    

    // cout << menu.discountManager.lists.at(0) ;
    // cout << menu.discountManager.lists.at(1) ;
    // cout << menu.discountManager.lists.at(2) ;
//     Time myTime;
// std::cout << "Real Time: " << myTime.getRealTime() << std::endl;
    // Time mytime ; 
    // mytime.updateRealTime() ; 
    // mytime.getFormattedTime() ; 
    // cout << mytime ; 

    // Date t ; 
    // t.getRealTime() ; 
    // cout << t ;
    // cin >> t ;
    // cout << t ; 

    // Discount
    // Discount discount(1,"ABC" ,20.9,1,1) ; 
    // cout << discount ;  
    // Time date; 
    // date.setMinute(11) ; 
    // date.setHour(1) ; 
    // Discount d1(1,"ABC",20.0,60,1) ; 
    // Order order(0,0,200000.0,date,"aBC",1,"BAC","BBB",0) ;
    // order.ApplyDiscount(d1) ; 
    // std::cout << order.GetTotalAmount(); 

}
