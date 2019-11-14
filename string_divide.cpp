string divide(int dividend, int divisor) {
   // check to see if dividend is 0, program terminates
   if (dividend == 0) return 0;
   int sign;
   string quotient;

   // check for whether there is + or - num
   if ((dividend < 0) ^ (divisor < 0)) sign = -1;
   else sign = 1;
   if (sign == -1) quotient.append("-");
   dividend = abs(dividend);
   divisor = abs(divisor);

   int absolute = dividend/divisor;
   int checker = dividend % divisor;

   string strabsolute = to_string(absolute);
   quotient.append(strabsolute);

   if (checker == 0) return quotient;

   quotient.append(".");

   int remainder = checker, index;
   map<int, int> num;

   bool infinite = false;

   while (remainder > 0 && !infinite) {
       if (num.find(remainder) != num.end()) {
          index = num[remainder];
	  infinite = true;
	  break;
       }
       else num[remainder] = quotient.size();
       remainder *= 10;

       // solve for the quotient, add to result
       int tempquotient = remainder / divisor;
       string strtemp = to_string(tempquotient);
       quotient.append(strtemp);
       remainder = remainder % divisor;
   }

   if (infinite) { 
     quotient.append(")");
     quotient.insert(index, "(");
   }

   return quotient;
}
~     
