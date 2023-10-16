int basis[d]; // basis[i] keeps the mask of the vector whose f value is i

int sz; // Current size of the basis

void insertVector(int mask) {
	for (int i = 0; i < d; i++) {
		if ((mask & 1 << i) == 0) continue; // continue if i != f(mask)

		if (!basis[i]) { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
			basis[i] = mask;
			++sz;
			
			return;
		}

		mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
	}
}

// query for k-th largest xor sum among subsets
// insert vector need to be from i := d - 1 -> 0
int query(int k) {
	int mask = 0;
 
	int tot = 1 << sz;
	for (int i = LOG_K - 1; i >= 0; i--)
		if (basis[i]) {
			int low = tot / 2;
 
			if ((low < k && (mask & 1 << i) == 0) ||
				(low >= k && (mask & 1 << i) > 0)) mask ^= basis[i];
 
			if (low < k) k -= low;
 
			tot /= 2;
		}
 
	return mask;
}