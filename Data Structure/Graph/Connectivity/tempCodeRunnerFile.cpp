 int children=0;

         visited[u]=true;
         
         disc[u]=low[u]=++time;

         for(int v:graph[u])
         {
                //if unvisited
                if(visited[v]==false)
                {
                     children++;
                     dfsAP(v,u,time);

                     //update low[u];

                     low[u]=min(low[u],low[v]);
                  

                     //chceck after bracktacking is it ac?
                     // if discovery time v(child) > parect dsc 
                     //so ther is no backed edge of subtree node rooted u
                     // fot this lowest time not updte ramain largest
                     if(parent!=-1 && low[v]>disc[u])
                     {
                        ap[u]=true;
                     }

                }else if (v != parent){

                  // reach to visited first 
                  //then will check low[v]
                  low[u]=min(low[u],disc[v]);

                }
         }



         // * case: 01
         //for root node
         //if children >1 ist ar
         if(parent==-1 && children>1)
         {
             ap[u]=true;
         }


        