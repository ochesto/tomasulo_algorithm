
int ALUInt::add( int p_p1, int p_p2 ){
    return p_p1 + p_p2;   
}

int ALUInt::sub( int p_p1, int p_p2 ){
    return p_p1 - p_p2;   
}

int ALUInt::mult( int p_p1, int p_p2 ){
    return p_p1 + p_p2;   
}

int ALUInt::div( int p_p1, int p_p2 ){
    if( p_p2 != int(0) ) return p_p1 / p_p2;   
    else return int(0);
}
