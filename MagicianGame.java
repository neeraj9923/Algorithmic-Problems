/**
 * 
 */
package com.algo;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;

/**
 * @author Neeraj
 * this problem breaks down to generating Powerset of({1,2,3,4,5})
 *
 */
public class MagicianGame {
     Integer arr[]={1,2,3,4,5};	
     ArrayList<Integer> arrayList=new ArrayList<Integer>(Arrays.asList(arr));
     static ArrayList<HashSet<Integer>> cards=new ArrayList<HashSet<Integer>>(6);
     static ArrayList<ArrayList<Integer>> allPartitions=new ArrayList<ArrayList<Integer>>(31);
     static int j=1;
     
     
	
	public void findPowerSet(ArrayList<Integer> arrayList,	int i){
		if(i<arrayList.size()){
			int x=arrayList.remove(i);
			findPowerSet(arrayList, i);
			arrayList.add(x);
			Collections.sort(arrayList);
			findPowerSet(arrayList, i+1);
		}
		if(arrayList.size()==i){
		System.out.println("Count : "+(MagicianGame.j-1) +" " +arrayList);
		if((MagicianGame.j-1)>0)
		MagicianGame.allPartitions.add(new ArrayList<Integer>(arrayList));
		populateCrads(arrayList,j-1);
		j++;
		}
	}
	
	public void populateCrads(ArrayList<Integer> arrayList,int j){
		for(Integer x:arrayList){
			HashSet<Integer> hashSet=MagicianGame.cards.get(x);
			hashSet.add(j);
			MagicianGame.cards.set(x,hashSet);
		}
	}
	

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		for(int i=0;i<6;i++){
			cards.add(new HashSet<Integer>());
		}
		MagicianGame magicianGame=new MagicianGame();
		magicianGame.findPowerSet(magicianGame.arrayList,0);
		for(int i=1;i<=cards.size()-1;i++){
			System.out.print("cardNo "+i+"  :");
			for(Integer x:cards.get(i)){
				System.out.print("  "+x);
			}
			System.out.println();
	}
		
		System.out.println("Enter all the Card No in Sorted Order where your DOB is present And Enter exit after giving Input");
		Scanner scan = new Scanner(System.in);
		ArrayList<Integer>arr=new ArrayList<Integer>();
		while(scan.hasNextInt()){
			int n = scan.nextInt();
			arr.add(n);
		}
		
		System.out.println(MagicianGame.allPartitions);
		System.out.println(MagicianGame.allPartitions.indexOf(arr)+1);
	}
}
