#include<iostream>
#include<memory>
#include<thread>
#include<mutex>
#include<queue>
#include <string>
#include<map>
#include<fstream>
using namespace std;


class Message {

public:
    Message(int id, int appId,string msg): mId(id),appId(appId),msg(msg) {}
    string getMessage() {
      return msg;
    }
    int getMId() { return mId;}
    int getAppId() { return appId;}

  private:
    int mId;
    int appId;
    string msg;
};



class Command {
  public:
    Command(Message msg,int type):msg(msg),type(type){}
    Command(const Command &) = default;
    pair<int,string> execute() {
      int appId = msg.getAppId();
      string str = msg.getMessage() + " type: "+ std::to_string(type);
      return make_pair(appId,str);
    }
    Message getMessage() {
      return msg;
    }
    int getType() { return type;}
  private :
    Message msg;
    int type;
};



class CommandQueue {
public:
 void addToQueue(const Command &com) {
   std::lock_guard<mutex> mu(m) ;
   commQueue.push(com);
 }

 Command getCommand() {
    std::lock_guard<mutex> mu(m) ;
    auto com = commQueue.front();
    commQueue.pop();
    return com;
}
static CommandQueue& getInstance() {
  static CommandQueue comm;
  return comm;
}

bool empty() {
  return commQueue.empty();
}

private:
  CommandQueue()= default;
  CommandQueue(const CommandQueue&) = delete;
  CommandQueue& operator=(const CommandQueue&) = delete;
  queue<Command> commQueue;
  std::mutex m;
};




class DiaViewer{

  public :

  void view() {

    cout<<" ========================= Diagonstic Viewer =========================="<<endl;
    for(auto i : msgQueue) {

        cout<< "************** Application : " <<  i.first << " START "<<endl;
        int ii = 0;
        for(auto si: i.second) {

          cout<< ii++ << ": "<< si <<endl;
        }
        cout<< "************** Application : " <<  i.first << " END   "<<endl;
        cout<<endl;
        cout<<endl;
    }

  }

  void htmlView() {

    ofstream myfile;
    myfile.open ("D:\\report.html");
    myfile << "<!DOCTYPE html><html><head></head><body>"; //starting html
    myfile << "<p><span style='font-weight: bold'>" <<" Diagonstic Viewer"<<"</span>"<<"</p>";
    int ii = 0;
    for(auto i : msgQueue) {

        myfile << "<p>" << "************** Application : " <<  i.first <<"Start  "<<"</p>" ;
        for(auto si: i.second) {

          myfile << "<p>" << ii++ << ": "<< si <<"</p>";
        }
          myfile << "<p>" << "************** Application : " <<  i.first << " END   "<<"</p>";
    }
    myfile << "</body></html>";
    myfile.close();

  }

  void allInOneView() {

    cout<<" ========================= Diagonstic Viewer Start =========================="<<endl;
    for(auto i : OneView) {
          cout<< i.Appid << ": "<< i.str <<endl;

    }
   cout<<" ========================= Diagonstic Viewer End  =========================="<<endl;
  }


  void allInOneView_html() {
    ofstream myfile;
    myfile.open ("D:\\report.html");
    myfile << "<!DOCTYPE html><html><head></head><body>"; //starting html
    myfile << "<p><span style='font-weight: bold'>" <<" Diagonstic Viewer"<<"</span>"<<"</p>";
      for(auto i : OneView) {
            myfile << "<p>" << i.Appid << ": "<< i.str <<"</p>";

      }
}
void prepareMsg() {

  auto &cQueue = CommandQueue::getInstance();
  while(!cQueue.empty()) {
    auto comm = cQueue.getCommand();
    auto pair = comm.execute();
    msgQueue[pair.first].emplace_back(pair.second);
    OneView.emplace_back(pair.first,pair.second);
  }
}

struct AllinOneView {
  AllinOneView(int id, string str):Appid(id),str(str){}
  int Appid;
  string str;
};


private:
  map<int,vector<string>> msgQueue;
  vector<AllinOneView> OneView;
};


int main() {

   Message msg(1,1,"Block is not prepare ");
   Message msg1(1,2,"Block is missing ");
   Message msg2(1,3,"Block is not all right ");
   Message msg3(1,4,"Block is not done yet");
   Message msg4(1,5,"Block is not prepare ");
   Message msg5(1,1,"Block is not prepare ");
   Message msg6(1,2,"Block is not prepare ");

   Command c1(msg,1);
   Command c2(msg1,2);
   Command c3(msg2,3);
   Command c4(msg3,1);
   Command c5(msg4,1);
   Command c6(msg5,1);
   Command c7(msg6,2);

  //Add command to queue ;

  CommandQueue::getInstance().addToQueue(c1);
  CommandQueue::getInstance().addToQueue(c2);
  CommandQueue::getInstance().addToQueue(c3);
  CommandQueue::getInstance().addToQueue(c4);
  CommandQueue::getInstance().addToQueue(c5);
  CommandQueue::getInstance().addToQueue(c6);
  CommandQueue::getInstance().addToQueue(c7);

 DiaViewer diag;
 diag.prepareMsg();

 diag.allInOneView();
 diag.allInOneView_html();

}
