priceof(pizza1,10).
priceof(pizza2,12).
sizeof(pizza1,12).
sizeof(pizza2,14).
shapeof(pizza1,square).
shapeof(pizza2,round).
        
area(Pizza,Squareinches) :-
         sizeof(Pizza,Side),
         shapeof(Pizza,square),
         Squareinches is Side * Side.

area(Pizza,Squareinches) :-
         sizeof(Pizza,Diameter),
         shapeof(Pizza,round),
         Radius is  Diameter / 2,
         Squareinches is 3.142 * (Radius * Radius).
squareinchprice(Pizza,Amount) :-
         area(Pizza,Squareinches),
         priceof(Pizza,Dollars),
         Amount is Dollars / Squareinches.

betterdeal(PizzaX,PizzaY) :-
      squareinchprice(PizzaX,Amount1),
      squareinchprice(PizzaY,Amount2),
      Amount1 < Amount2.