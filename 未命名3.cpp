void GA::Variation() {
	int i, j;
	for (i = 0; i < PS; i++) {
		if (IsVariation()) {
			for (j = 0; j < NUM; j++) {
				if (IsVariation()) {
					zq[i].gene[j] = zq[i].gene[j] ? 0 : 1;
				}
			}
		}
	}
}

