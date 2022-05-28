class Solution {
private:
    vector<string> unit{"", "One", "Two", "Three", "Four",
                            "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> ten{"","Ten", "Twenty", "Thirty", "Forty",
                            "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> unit_and_ten{"Ten","Eleven", "Twelve", "Thirteen", "Fourteen",
                            "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
public:
    string convert(int num)
    {
        string ret;
        int units = num % 10;
        num = num / 10;
        int tens = num % 10;
        int hurdreds = num / 10;

        if(hurdreds)
        {
            ret += unit[hurdreds] + " " + "Hundred";
            if(tens || units)
                ret += " ";
        }

        if(tens)
        {
            if(tens != 1)
            {
                ret += (ten[tens]);
                if(units)
                {
                    ret += " ";
                }
            }
            else
            {
                ret += unit_and_ten[units];
                return ret;
            }
        }

        if(units)
        {
            ret += unit[units];
        }

        return ret;
    }
    string numberToWords(int num) {

        int base = num % 1000;
        num = num / 1000;
        int thousand =  num % 1000;
        num = num / 1000;
        int million = num % 1000;
        int billion = num / 1000;

        string ret;

        if(billion)
        {
            ret += unit[billion] + " " + "Billion";
            if(million || thousand || base)
                ret += " ";
        }

        if(million)
        {
            ret += convert(million) + " " + "Million";
            if(thousand || base)
                ret += " ";
        }


        if(thousand)
        {
            ret += convert(thousand) + " " + "Thousand";
            if(base)
                ret += " ";
        }

        if(base)
        {
            ret += convert(base);
        }

        if(ret == "")
            return "Zero";

        return ret;
    }
};