#include "bitio.hh"


/////////

// Construct with one of either an input stream or output (the other null)
BitIO::BitIO(std::ostream* os, std::istream* is){
    assert(!(os and is) or (os or is));

    os_ = os;
    is_ = is;
    bitnum_ =0;
}

// Flushes out any remaining output bits and trailing zeros, if any:
BitIO::~BitIO(){
    if(os_ and bitnum_ >0){
        *os_ << writeByte_;
    }
}

// Output a single bit (buffered)
void BitIO::output_bit(bool bit){
    //True = Left = 1
    //False = Right = 0

    //check for output stream
    if(!os_)
    {
        assert(false);
    }
    //set some bits

    if(bit)
    {
        writeByte_ |= (1 << (7-bitnum_));
    }
    bitnum_++;
    
    if(bitnum_ ==8){
        os_->put(writeByte_);
        //*os_ << writeByte_;
        bitnum_ = 0;
        writeByte_ = char(0x0);
    }

    //push and reset stuff after filling up a byte
    
    //set hanging bits of last byte to 0
 
}

// Read a single bit (or trailing zero)
bool BitIO::input_bit(){
    //TRUE MEANS 1, FALSE MEANS 0
    //read a byte from string, read first bit from that byte and until run out of 8 bits from byte, read from same 8 bits.

    if(!is_)
    {
        assert(false);
    }
    if(bitnum_ == 0)
    {
        
        storedByte_ = is_->get();
        //*is_ >> storedByte_;
    }
    bool relevBit = (storedByte_ >> (7-bitnum_)) & 0x1; 


    bitnum_++;
    if(bitnum_ == 8)
    {
        bitnum_ = 0;
    }
    return relevBit;

}



