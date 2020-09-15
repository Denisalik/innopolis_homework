if ln input input.lock
#if there is no lock, then in my case race condition is happened around ~600 number
#critical region is file where we store the numbers 
then
lastnumber=`tail -1 input`
nextnumber=$((lastnumber+1))
echo ${nextnumber} >> input
rm input.lock
fi
