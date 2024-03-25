class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        string clockwise="";
        string anticlockwise="";
        
        clockwise=str1;
        rotate(clockwise.begin(),clockwise.begin()+2,clockwise.end());
        
        anticlockwise=str1;
        rotate(anticlockwise.begin(),anticlockwise.begin()+anticlockwise.size()-2,anticlockwise.end());
        
        if(str2==clockwise || str2==anticlockwise)
            return true;
        else
            return false;
    }

};
