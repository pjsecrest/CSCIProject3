class Item
{
    private:
        string name;
        int cost;
    public:
        Item();
        Item(string name_, int cost_);
        string getName();
        void setName(string name_);
        int getCost();
        void setCost(int cost_);
};