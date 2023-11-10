USE PBL2

CREATE TABLE Orders_Discount (
    DiscountID INT,
    OrderID INT,
    PRIMARY KEY (OrderID, DiscountID),
    FOREIGN KEY (OrderID) REFERENCES Orders(OrderID),
    FOREIGN KEY (DiscountID) REFERENCES Discount(DiscountID)
);

