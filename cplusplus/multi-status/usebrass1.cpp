#include <iostream>

#include "brass.hxx"

int main()
{
    using std::cout;
    using std::endl;

    Brass Piggy("Porcelot Pigg", 381299, 4000.0);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.0);
    Piggy.ViewAcct();
    cout<<endl;

    Hoggy.ViewAcct();
    cout<<endl;
    cout<<"Depositing $1000 into the Hogg Accout:\n";
    Hoggy.WithDraw(1000.0);
    cout<<"New balance: $"<<Hoggy.Balance()<<endl;
    cout<<"WithDrawing $4200 form the pigg accout:\n";
    Piggy.WithDraw(4200.0);
    cout<<"Pigg accout balance: $"<<Piggy.Balance()<<endl;
    cout<<"WithDrawing $4200 from the Hogg accout:\n";
    Hoggy.WithDraw(4200.0);
    Hoggy.ViewAcct();


}