
using ll = long long;

// Fazer map de ll pro valor da pontuação máxima
map<ll,int> g_dp_st;

int main()
{
	struct State state(short num_discos, short num_cores, short num_jogadores)

	struct Game game(g_num_discos, g_num_cores, g_num_jogadores);
   	//ofstream ofsGame("game.txt", ofstream::out);
   	//ofsGame << game;
   	//ofsGame.close();

   	//ofstream ofsStair("stair.txt", ofstream::out);
   	//ofsStair << "Stair_states {" << endl;
   	//for (unsigned int i = 0; i < g_ids.size(); i++) {
   	//	ofsStair << "\t" << i << "->" << g_ids[i] << endl;
   	//}
   	//ofsStair << "}" << endl;
   	//ofsStair.close();

   	// st.escada[0] = 1;
   	// st.escada[1] = 2;
   	// st.escada[2] = 3;

   	// st.peao[0] = 1;
    	// st.peao[1] = 0;
   	// st.peao[2] = 0;

   	// st.jogadores[0][0] = 0;
   	// st.jogadores[0][1] = 1;
   	// st.jogadores[0][2] = 2;

   	// st.jogadores[1][0] = 3;
   	// st.jogadores[1][1] = 0;
   	// st.jogadores[1][2] = 1;

   	// ll ll_st = encode(st);
   	//
   	// decode(ll_st, st);

   //	cerr << "BEGIN" << endl;
   	clock_t start, end;
   	start = clock();
   	dp(game, st);
   	end = clock();

   //	cerr << "END" << endl;

   	ofsDp << endl << "MAP (" << g_dp_st.size() << ")"  << endl;
   	for (auto s: g_dp_st) {
   		ofsDp << s.first << " -> " << s.second << endl;
   	}

   	ofsDp.close();

   	cout << g_dp_st.size() << " " << (((float)(end - start))/CLOCKS_PER_SEC) << endl;

   	return 0;
}
