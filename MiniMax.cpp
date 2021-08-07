int minimax(int depth, int nodeIndex,
            bool maximizingPlayer,
            int values[], int alpha, 
            int beta) {
    if (depth == 3)
        return values[nodeIndex];
    if (maximizingPlayer) {
        int best = MIN;
        for (int i = 0; i < 2; i++) {
            int val = minimax(depth + 1, nodeIndex * 2 + i, 
                              false, values, alpha, beta);
            best = max(best, val);
            alpha = max(alpha, best);
            if (beta <= alpha)
                break;
        }
        return best;
