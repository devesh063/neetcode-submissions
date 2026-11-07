class Node 
{
public:
   vector<Node*> links;
   bool isFlag;

   Node()
   {
      links.resize(26,nullptr);
      isFlag = false;
   }
   
   void setEnd()
   {
       isFlag = true;   
   }

   bool containsKey(char ch)
   {
      return (links[ch-'a'] != nullptr);
   }

   void put(char ch, Node *temp)
   {
      links[ch-'a'] = temp;
   }

   Node* get(char ch)
   {
     return links[ch-'a'];
   }

   bool isEnd()
   {
    return isFlag;
   }
};


class PrefixTree 
{
public:
    Node *root = new Node();

    PrefixTree() 
    {
        
    }
    
    void insert(string word) 
    {
        int n = word.size();
        Node *node = root;

        for(int i=0; i<n; i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }   
        node->setEnd(); 
    }
    
    bool search(string word) 
    {
       int n = word.size();
       Node *node = root;

       for(int i=0; i<n; i++)
       {
         if(!node->containsKey(word[i]))
         {
             return false;  
         }
         node = node->get(word[i]);
       }

       return node->isEnd();    
    }
    
    bool startsWith(string prefix) 
    {
       Node *node = root;

       for(int i=0; i<prefix.length(); i++)
       {
         if(!node->containsKey(prefix[i]))
           return false;
         node = node->get(prefix[i]);
       }  
       return true;  
    }
};
