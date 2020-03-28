class node :                            #그래프의 정점을 뜻함
    def __init__(self,name):
        self.edge = dict()            # 정점의 사이의 거리를 "vertex : weight"로 나타내었다.
        self.name = name
        self.distance = {self :0}   #최단거리를 저장하기 위한 맴버변수
    def Insert_edge(self,vertex,weight) :
        self.edge[vertex] = weight
    def Display(self):
        print(self.name)
        
def Search_dijkstra(distances,ended_vertex):   
    searching_vertex = dict()                                       # 탐색이 끝난 정점을 제외한 정점을 찾는다.
    for n in set(distances) - ended_vertex :
        searching_vertex[n] = distances[n]
    try : 
        now_reference = min(searching_vertex.items(),key = lambda t:t[1])   #현재 탐색할 최소 vertex를 찾는다.
    except ValueError :
        print("더이상 탐색을 할수 없습니다")
        return False
    end_vertex.add(now_reference[0])
    for n in now_reference[0].edge:
        try :                                                                 # 처음접근한 vertex를 예외처리한다.
            if(distances[n] > now_reference[0].edge[n] + now_reference[1]) :
                distances[n] = now_reference[0].edge[n] + now_reference[1]
        except :
            distances[n] = now_reference[0].edge[n] + now_reference[1]
                                                    # 0은 해당 객체, 1은 cost를 의미
                                                    #now_reference[0].edge[n]는 해당객체의 n에 대한 value값을 찾는다.
    return True


def Display_visited(distances,end_vertex) :
    for n in distances :
        print(n.name,end = '='); print(distances[n],end ='  |  ')
    print("까지 탐색, 거리가 확정된것은 ")
    for n in end_vertex :
        print(n.name, end = ' ')
    print("이다\n")


인천 = node('인천') ; 서울 = node('서울'); 강릉 = node('강릉')
천안 = node('천안');  청주 = node('청주'); 동해 = node('동해')
대전 = node('대전');  울진 = node('울진'); 대구 = node('대구')
광주 = node('광주');  울산 = node('울산'); 부산 = node('부산')


인천.Insert_edge(서울,7); 인천.Insert_edge(천안,1)
서울.Insert_edge(인천,3); 서울.Insert_edge(청주,8); 서울.Insert_edge(강릉,5)
강릉.Insert_edge(서울,3); 강릉.Insert_edge(동해,3)
천안.Insert_edge(인천,3); 천안.Insert_edge(청주,4); 천안.Insert_edge(대전,4)
청주.Insert_edge(서울,13); 청주.Insert_edge(천안,3); 청주.Insert_edge(동해,1);청주.Insert_edge(울진,2)
동해.Insert_edge(강릉,5); 동해.Insert_edge(청주,2); 동해.Insert_edge(울진,5)
대전.Insert_edge(천안,5); 대전.Insert_edge(울진,5); 대전.Insert_edge(대구,3); 대전.Insert_edge(광주,3)
울진.Insert_edge(동해,3); 울진.Insert_edge(청주,2); 울진.Insert_edge(대전,5); 울진.Insert_edge(울산,2)
광주.Insert_edge(대전,3); 광주.Insert_edge(대구,6); 광주.Insert_edge(부산,5)
대구.Insert_edge(대전,6); 대구.Insert_edge(청주,6); 대구.Insert_edge(울산,2); 대구.Insert_edge(부산,1)
울산.Insert_edge(울진,1); 울산.Insert_edge(부산,2)
부산.Insert_edge(광주,4); 부산.Insert_edge(울산,3)


end_vertex = set()
while Search_dijkstra(서울.distance,end_vertex) :
    Display_visited(서울.distance,end_vertex)
