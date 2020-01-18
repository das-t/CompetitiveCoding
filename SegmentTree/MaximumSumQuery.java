import java.util.*;
import java.io.*;

class Node{
    long maxSum,totalSum,maxSuffixSum,maxPrefixSum;
    public Node(){maxSum=0;totalSum=0;maxSuffixSum=0;maxPrefixSum=0;}
    public void setLeaf(int value){maxSum=value;totalSum=value;maxSuffixSum=value;maxPrefixSum=value;}
    public void setCompare(Node node1,Node node2){
        maxSum = Math.max(Math.max(Math.max(node1.maxSum,node2.maxSum),
                                  Math.max(node1.totalSum+node2.maxPrefixSum,node1.maxSuffixSum+node2.totalSum)
                                  ),node1.maxSuffixSum+node2.maxPrefixSum);
        totalSum = node1.totalSum + node2.totalSum;
        maxPrefixSum = Math.max(node1.maxPrefixSum,node1.totalSum+node2.maxPrefixSum);
        maxSuffixSum = Math.max(node2.maxSuffixSum,node2.totalSum+node1.maxSuffixSum);
    }
}

class SegmentTree{
    int size;
    Node tree[] = null;
    
    public SegmentTree(int[] array){
        size = array.length;
        tree = new Node[4*size];
        for(int i=0;i<tree.length;i++)
            tree[i] =new Node();
        buildTree(0,size-1,1,array);
    }
    
    private void buildTree(int left,int right,int treeNode,int[] array){
        if(left==right){
            tree[treeNode].setLeaf(array[left]);
            return;
        }
        int mid = (left+right)/2;
        buildTree(left,mid,2*treeNode,array);
        buildTree(mid+1,right,2*treeNode+1,array);
        tree[treeNode].setCompare(tree[2*treeNode],tree[2*treeNode+1]);
    }
    
    public long query(int minIndex,int maxIndex){
        Node ansNode = queryTree(0,size-1,1,minIndex,maxIndex);
        return ansNode.maxSum;
    }
    
    private Node queryTree(int left,int right,int treeIndex,int arrayMinIndex,int arrayMaxIndex){
        if(arrayMinIndex>right || arrayMaxIndex<left)
            return null;
        else if(arrayMinIndex<=left && right<=arrayMaxIndex)
            return tree[treeIndex];
        int mid = (left+right)/2;
        Node nodeLeft = queryTree(left,mid,2*treeIndex,arrayMinIndex,arrayMaxIndex);
        Node nodeRight = queryTree(mid+1,right,2*treeIndex+1,arrayMinIndex,arrayMaxIndex);
        return setCompareReturnNode(nodeLeft,nodeRight);
    }
    
    private Node setCompareReturnNode(Node node1,Node node2){
        if(node1==null && node2==null)
            return null;
        else if(node1==null)
            return node2;
        else if(node2==null)
            return node1;
        Node node = new Node();
        node.setCompare(node1,node2);
        return node;
    }
    
    public void printTree(){
        System.out.println("---- Tree ----");
        for(int i=0;i<tree.length;i++)
            System.out.println(tree[i].maxSum+" "+tree[i].totalSum+" "+tree[i].maxPrefixSum+" "+tree[i].maxSuffixSum);
        System.out.println("---- ---- ----");
    }
}
public class Main {
	public static void main(String[] args) {
		// Write your code here
        FastReader reader = new FastReader();
        int elements = reader.nextInt();
        int array[] = new int[elements];
        for(int i=0;i<elements;i++)
            array[i] = reader.nextInt();
        int queries = reader.nextInt();
        SegmentTree segTree = new SegmentTree(array);
        // segTree.printTree();
        while(queries-->0){
            int minIndex = reader.nextInt();
            int maxIndex = reader.nextInt();
            System.out.println(segTree.query(minIndex-1,maxIndex-1));
        }
	}

    static class FastReader { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() { 
            br = new BufferedReader(newInputStreamReader(System.in)); 
        } 
  
        String next() { 
            while (st == null || !st.hasMoreElements()) { 
                try{ 
                    st = new StringTokenizer(br.readLine()); 
                } catch (IOException  e) { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() { 
            String str = ""; 
            try{ 
                str = br.readLine(); 
            } catch (IOException e) { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    }
}