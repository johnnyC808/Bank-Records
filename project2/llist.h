class llist
{
private:
    record * start;
    char filename[20];
    int readfile();
    int writefile();
    void cleanup();

public:
    llist();
    llist(char[]);
    ~llist();
    void addRecord(int, char [], char []);
    int findRecord(int);
    void printAllRecords();
    int deleteRecord(int);
};
