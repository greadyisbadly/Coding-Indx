void lsh(){
	sort(g.begin(),g.end());
	g.erase(unique(g.begin(),g.end()),g.end());
}